#include <pthread.h> // Inclui a biblioteca POSIX Threads para trabalhar com threads e mutexes.
#include <stdio.h>   // Inclui a biblioteca padrão de entrada/saída para usar printf.
#include <unistd.h>  // Inclui a biblioteca para funções como sleep (pausa em segundos).

// Declara dois mutexes globais (lock1 e lock2) para sincronizar o acesso a recursos compartilhados.
pthread_mutex_t lock1, lock2;

// Função executada pela thread 1.
void* thread1(void* arg) {
    // Imprime mensagem indicando que a thread 1 está tentando adquirir o mutex lock1.
    printf("Thread 1: Tentando adquirir lock1\n");
    // Bloqueia lock1; a thread espera se lock1 já estiver bloqueado por outra thread.
    pthread_mutex_lock(&lock1);
    // Confirma que a thread 1 adquiriu lock1 com sucesso.
    printf("Thread 1: Adquiriu lock1\n");
    // Pausa a execução por 1 segundo para simular trabalho e aumentar a chance de concorrência.
    sleep(1);
    // Imprime mensagem indicando que a thread 1 está tentando adquirir o mutex lock2.
    printf("Thread 1: Tentando adquirir lock2\n");
    // Bloqueia lock2; a thread espera se lock2 já estiver bloqueado.
    pthread_mutex_lock(&lock2);
    // Confirma que a thread 1 adquiriu lock2 com sucesso.
    printf("Thread 1: Adquiriu lock2\n");
    // Imprime mensagem indicando que a thread 1 completou sua tarefa.
    printf("Thread 1 completou\n");
    // Libera lock2, permitindo que outras threads o adquiram.
    pthread_mutex_unlock(&lock2);
    // Libera lock1, permitindo que outras threads o adquiram.
    pthread_mutex_unlock(&lock1);
    // Retorna NULL para indicar que a thread terminou sua execução.
    return NULL;
}

// Função executada pela thread 2 (note que segue a mesma ordem de aquisição: lock1 → lock2).
void* thread2(void* arg) {
    // Imprime mensagem indicando que a thread 2 está tentando adquirir o mutex lock1.
    printf("Thread 2: Tentando adquirir lock1\n");
    // Bloqueia lock1; a thread espera se lock1 já estiver bloqueado por outra thread.
    pthread_mutex_lock(&lock1);
    // Confirma que a thread 2 adquiriu lock1 com sucesso.
    printf("Thread 2: Adquiriu lock1\n");
    // Pausa a execução por 1 segundo para simular trabalho e aumentar a chance de concorrência.
    sleep(1);
    // Imprime mensagem indicando que a thread 2 está tentando adquirir o mutex lock2.
    printf("Thread 2: Tentando adquirir lock2\n");
    // Bloqueia lock2; a thread espera se lock2 já estiver bloqueado.
    pthread_mutex_lock(&lock2);
    // Confirma que a thread 2 adquiriu lock2 com sucesso.
    printf("Thread 2: Adquiriu lock2\n");
    // Imprime mensagem indicando que a thread 2 completou sua tarefa.
    printf("Thread 2 completou\n");
    // Libera lock2, permitindo que outras threads o adquiram.
    pthread_mutex_unlock(&lock2);
    // Libera lock1, permitindo que outras threads o adquiram.
    pthread_mutex_unlock(&lock1);
    // Retorna NULL para indicar que a thread terminou sua execução.
    return NULL;
}

int main() {
    // Declara duas variáveis para armazenar os identificadores das threads.
    pthread_t t1, t2;

    // Inicializa o mutex lock1 com atributos padrão (NULL).
    pthread_mutex_init(&lock1, NULL);
    // Inicializa o mutex lock2 com atributos padrão (NULL).
    pthread_mutex_init(&lock2, NULL);

    // Cria a thread 1, que executará a função thread1, passando NULL como argumento.
    pthread_create(&t1, NULL, thread1, NULL);
    // Cria a thread 2, que executará a função thread2, passando NULL como argumento.
    pthread_create(&t2, NULL, thread2, NULL);

    // Espera a thread 1 terminar sua execução antes de prosseguir.
    pthread_join(t1, NULL);
    // Espera a thread 2 terminar sua execução antes de prosseguir.
    pthread_join(t2, NULL);

    // Destroi o mutex lock1, liberando seus recursos.
    pthread_mutex_destroy(&lock1);
    // Destroi o mutex lock2, liberando seus recursos.
    pthread_mutex_destroy(&lock2);

    // Imprime mensagem indicando que o programa terminou.
    printf("Programa finalizado\n");
    // Retorna 0 para indicar que o programa terminou com sucesso.
    return 0;
}