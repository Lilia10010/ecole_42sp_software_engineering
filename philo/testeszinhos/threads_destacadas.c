#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 5

void *print_id(void *arg) {
    int id = *(int *)arg;
    printf("Hello from thread %d\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    pthread_attr_t attr; // Objeto para atributos da thread

    // Inicializa o objeto de atributos
    pthread_attr_init(&attr);
    // Configura as threads como destacadas
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        // Passa &attr em vez de NULL
        if (pthread_create(&threads[i], &attr, print_id, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
        }
    }

    // Destrói o objeto de atributos
    pthread_attr_destroy(&attr);

    // Não precisa de pthread_join, pois as threads são destacadas
    printf("All threads launched.\n");
    return 0;
}