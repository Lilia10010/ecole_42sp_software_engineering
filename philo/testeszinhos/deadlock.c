#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void* thread1(void* arg) {
    printf("Thread 1: Tentando adquirir lock1\n");
    pthread_mutex_lock(&lock1);
    printf("Thread 1: Adquiriu lock1\n");
    sleep(1); // p/ simular algo
    printf("Thread 1: Tentando adquirir lock2\n");
    pthread_mutex_lock(&lock2);
    printf("Thread 1: Adquiriu lock2\n");
    printf("Thread 1 completou\n");
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void* thread2(void* arg) {
    printf("Thread 2: Tentando adquirir lock2\n");
    pthread_mutex_lock(&lock2);
    printf("Thread 2: Adquiriu lock2\n");
    sleep(1); // p/ simular algo
    printf("Thread 2: Tentando adquirir lock1\n");
    pthread_mutex_lock(&lock1);
    printf("Thread 2: Adquiriu lock1\n");
    printf("Thread 2 completou\n");
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Inicializa os mutexes
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    // Cria as threads
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    // Espera as threads terminarem
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroi os mutexes
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);

    printf("Programa finalizado\n");
    return 0;
}