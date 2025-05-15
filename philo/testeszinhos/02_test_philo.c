#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t *forks;
long *last_meal_time;
int running = 1;

long get_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void think(int id)
{
    printf("%ld ms fisolofo %d está pensando 🤔 \n", get_time_ms(), id);
    usleep(200000);
}

void eat(int id)
{
    printf("%ld ms fisolofo %d esta comendo 🍝 \n", get_time_ms(), id);
    usleep(300000);
    last_meal_time[id] = get_time_ms();
}

void pickup_forks(int id)
{
	int left_fork = id;
	int right_fork = (id + 1) % NUM_PHILOSOPHERS;

	if (id % 2 == 0)
    {
        pthread_mutex_lock(&forks[left_fork]);
        printf("%ld ms filósofo %d pegou o garfo esquerdo %d 🍴\n", get_time_ms(), id, left_fork);
        usleep(100000);  // Pequeno delay para simular tempo de ação
        
        pthread_mutex_lock(&forks[right_fork]);
        printf("%ld ms filósofo %d pegou o garfo direito %d 🍴\n", get_time_ms(), id, right_fork);
    }
    else
    {
        pthread_mutex_lock(&forks[right_fork]);
        printf("%ld ms filósofo %d pegou o garfo direito %d 🍴\n", get_time_ms(), id, right_fork);
        usleep(100000);  // Pequeno delay para simular tempo de ação
        
        pthread_mutex_lock(&forks[left_fork]);
        printf("%ld ms filósofo %d pegou o garfo esquerdo %d 🍴\n", get_time_ms(), id, left_fork);
    }
}

void putdown_forks(int id)
{
	int left_fork = id;
	int right_fork = (id + 1) % NUM_PHILOSOPHERS;

	if (id % 2 == 0)
    {
        pthread_mutex_unlock(&forks[right_fork]);
        pthread_mutex_unlock(&forks[left_fork]);
    }
    else
    {
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
    }
    
    printf("%ld ms filósofo %d largou os garfos\n", get_time_ms(), id);
}

void *philosopher(void *arg)
{
    int id = *(int *)arg;
        while (running)
    {
        think(id);
        pickup_forks(id);
        eat(id);
        putdown_forks(id);
    }
    return (NULL);
}

void *monitor(void *arg)
{
    (void)arg;
    while(running)
    {
        int i = 0;

        long now = get_time_ms();
        while (i < NUM_PHILOSOPHERS)
        {
            if (now - last_meal_time[i] > 70000)
            {
                printf("%ld filósofo %d morreu de fome 💀 \n", now, i);
				running = 0;
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
    pthread_t *philos;
    pthread_t watcher;
    int *ids;
	long start = get_time_ms();
	

	forks = (pthread_mutex_t *)malloc(NUM_PHILOSOPHERS * sizeof(pthread_mutex_t));
	last_meal_time = (long *)malloc(NUM_PHILOSOPHERS * sizeof(long));
	philos = (pthread_t *)malloc(NUM_PHILOSOPHERS * sizeof(pthread_t));
	ids = (int *)malloc(NUM_PHILOSOPHERS * sizeof(int));

	if (!forks || !last_meal_time || !philos || !ids)
	{
		printf("Erro na alocação de memória\n");
		return (1);
	}

	//p inicializar as mutex e tempo de refeição
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        last_meal_time[i] = start;
        ids[i] = i;
    }
    
    //hreads dos filósofos
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
		pthread_create(&philos[i], NULL, philosopher, &ids[i]);

	pthread_create(&watcher, NULL, monitor, NULL);

	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
		pthread_join(philos[i], NULL);

	pthread_join(watcher, NULL);

	//liberar memoria e destruir mutex
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
		pthread_mutex_destroy(&forks[i]);

	free(forks);
	free(last_meal_time);
	free(philos);
	free(ids);

    printf("simulação finalizada com sucesso \n");

    return (0);

}