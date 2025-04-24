#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

pthread_mutex_t fork01 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t fork02 = PTHREAD_MUTEX_INITIALIZER;

long last_meal_time[2];
int running = 1;

long get_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void think(int id)
{
    printf("%ld ms fisolofo %d está pensando \n", get_time_ms(), id);
    usleep(200000);
}

void eat(int id)
{
    printf("%ld ms fisolofo %d esta comendo \n", get_time_ms(), id);
    usleep(300000);
    last_meal_time[id] = get_time_ms();
}

void *philosopher(void *arg)
{
    int id = *(int *)arg;
    pthread_mutex_t *first;
    pthread_mutex_t *second;

    if (id == 0) 
    {
        first = &fork01;
        second = &fork02;
    } else 
    {
        first = &fork02;
        second = &fork01;
    }
    

    while (1)
    {
        think(id);
        pthread_mutex_lock(first);
        printf("%ld ms fisolofo %d pegou o 1° garfo 🍴\n", get_time_ms(), id);
        usleep(100000);

        pthread_mutex_lock(second);
        printf("%ld ms fisolofo %d pegou o 2° garfo 🍴\n", get_time_ms(), id);

        eat(id);

        pthread_mutex_unlock(second);
        pthread_mutex_unlock(first);
        printf("%ld ms filósofo %d largou os galfus \n", get_time_ms(), id);
    }
    return (NULL);
}

void *monitor(void *arg)
{
    (void)arg;
    while(1)
    {
        int i = 0;

        long now = get_time_ms();
        while (i < 2)
        {
            if (now - last_meal_time[i] > 70000)
            {
                printf("%ld filósofo %d morreu de fome 💀 \n", now, i);
                exit(1);
            }
            ++i;
        } 
        usleep(10000);
    }
    return (NULL);
}

int main(void)
{
    pthread_t philos[2];
    pthread_t watcher;
    int ids[2] = {0, 1};

    long start = get_time_ms();
    last_meal_time[0] = start;
    last_meal_time[1] = start;

    pthread_create(&philos[0], NULL, philosopher, &ids[0]);
    pthread_create(&philos[1], NULL, philosopher, &ids[1]);

    pthread_create(&watcher, NULL, monitor, NULL);

    pthread_join(philos[0], NULL);
    pthread_join(philos[1], NULL);
    pthread_join(watcher, NULL);

    printf("simulação finalizada com sucesso \n");

    return (0);

}