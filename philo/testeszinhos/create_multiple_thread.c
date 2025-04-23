#include <stdio.h>   // Inclui a biblioteca padrão de entrada/saída para usar printf e perror.
#include <pthread.h> // Inclui a biblioteca POSIX Threads para criar e gerenciar threads.

// Define uma constante para o número de threads a serem criadas (5 threads).
#define NUM_THREADS 11
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
// Função executada por cada thread, recebe um argumento (ID da thread) e imprime uma mensagem.
void *print_id(void *arg) {
    // Converte o argumento genérico (void*) para um ponteiro para int e obtém o valor do ID.
    int id = *(int *)arg;
	pthread_mutex_lock(&print_mutex);
    // Imprime uma mensagem indicando o ID da thread que está executando.
    printf("Hello from thread %d\n", id);
    // Retorna NULL para indicar que a thread terminou sua execução.
	pthread_mutex_unlock(&print_mutex);
    return NULL;
}

int main() {
    // Declara um array para armazenar os identificadores das threads (pthread_t).
    pthread_t threads[NUM_THREADS];
    // Declara um array para armazenar os IDs das threads (números de 1 a 5).
    int thread_ids[NUM_THREADS];

    // Loop para criar NUM_THREADS (5) threads.
    for (int i = 0; i < NUM_THREADS; i++) {
        // Atribui um ID único (de 1 a 5) para cada thread no array thread_ids.
        thread_ids[i] = i + 1;
        // Cria uma thread, armazenando seu identificador em threads[i].
        // Passa NULL para atributos padrão, print_id como função da thread, e &thread_ids[i] como argumento.
        if (pthread_create(&threads[i], NULL, print_id, &thread_ids[i]) != 0) {
            // Se pthread_create falhar, imprime uma mensagem de erro com detalhes.
            perror("Failed to create thread");
			exit(1); // para parar caso uma dê errado, se quiser continuar é só retirar esta linha
        }
    }

    // Loop para esperar que todas as threads terminem.
    for (int i = 0; i < NUM_THREADS; i++) {
        // Bloqueia a thread principal até que a thread threads[i] termine sua execução.
        pthread_join(threads[i], NULL);
    }

    // Imprime uma mensagem indicando que todas as threads concluíram.
    printf("All threads completed.\n");
    // Retorna 0 para indicar que o programa terminou com sucesso.
    return 0;
}

/*
typedef struct {
    int id;
    double resultado;
} ThreadResultado;

void *processar(void *arg) {
    ThreadResultado *res = malloc(sizeof(ThreadResultado));
    res->id = *(int *)arg;
    res->resultado = 3.14;
    return res;
}
*/