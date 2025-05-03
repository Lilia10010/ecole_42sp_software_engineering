/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:04:19 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/03 01:25:12 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

pthread_mutex_t *forks;     // array dinâmico de mutexes para os garfos
long *last_meal_time;       // array para rastrear a última refeição de cada filósofo
int running = 1;
long start_time;

long get_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

   return (((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L)) - start_time);
}


void handle_sleep(int id)
{
    printf("%ld ms fisolofo %d está dormindo 🛌 💤\n", get_time_ms(), id);
    usleep(SLEEP_PHILO * 1000);
    printf("%ld ms fisolofo %d está pensando 🤔 \n", get_time_ms(), id);
}

void handle_eat(int id)
{
    static int count = 1;
    
    
    printf("%ld ms fisolofo %d esta comendo 🍝 [%i]\n", get_time_ms(), id, count++);
    usleep(EAT_PHILO * 1000);
    last_meal_time[id] = get_time_ms();
    
    
}

// Função para pegar os garfos em uma ordem que evite deadlock
void pickup_forks(int id)
{
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;
    
    if (id % 2 == 0)
    {
       pthread_mutex_lock(&forks[left_fork]);
        printf("%ld ms filósofo %d pegou o garfo esquerdo %d 🍴\n", get_time_ms(), id, left_fork);
        
        pthread_mutex_lock(&forks[right_fork]);
        printf("%ld ms filósofo %d pegou o garfo direito %d 🍴\n", get_time_ms(), id, right_fork);
    }
    else
    {
        pthread_mutex_lock(&forks[right_fork]);
        printf("%ld ms filósofo %d pegou o garfo direito %d 🍴\n", get_time_ms(), id, right_fork);
        
        pthread_mutex_lock(&forks[left_fork]);
        printf("%ld ms filósofo %d pegou o garfo esquerdo %d 🍴\n", get_time_ms(), id, left_fork);
    }
}

// Função para soltar os garfos
void putdown_forks(int id)
{
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;
    
    // Libera os garfos na ordem inversa em que foram pegos
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
    
    printf("%ld ms filósofo %d largou os garfos 👐\n", get_time_ms(), id);
}

void *philosopher(void *arg)
{
    int id = *(int *)arg;
    printf("pos criação do par --->%d\n", id);

    // if (id % 2 != 0)
    // {
    //     usleep(1000);
    // }
    
    while (running)
    {
        pickup_forks(id);
        handle_eat(id);
        putdown_forks(id);
        handle_sleep(id);
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
            if (now - last_meal_time[i] > DIE_PHILO)
            {
                
                printf("tempo da última  refeição%ld\n", now - last_meal_time[i]);
                printf("%ld ms filósofo %d morreu de fome 💀\n", now, i);
                running = 0;
                //return (NULL);
                exit(1);
            }
            ++i;
        }
        usleep(5000);

    }
    return (NULL);
}

int main(void)
{
    pthread_t *philos;
    pthread_t watcher;
    int *ids;
    int i;
    
    start_time = get_time_ms();
    forks = (pthread_mutex_t *)malloc(NUM_PHILOSOPHERS * sizeof(pthread_mutex_t));
    last_meal_time = (long *)malloc(NUM_PHILOSOPHERS * sizeof(long));
    philos = (pthread_t *)malloc(NUM_PHILOSOPHERS * sizeof(pthread_t));
    ids = (int *)malloc(NUM_PHILOSOPHERS * sizeof(int));
    
    if (!forks || !last_meal_time || !philos || !ids) {
        fprintf(stderr, "Erro: falha na alocação de memória\n");
        return 1;
    }
    // create thread de monitoramento
    pthread_create(&watcher, NULL, monitor, NULL);

    i = 0;    
    // init mutexes e tempos de refeição
    while (i < NUM_PHILOSOPHERS){
        pthread_mutex_init(&forks[i], NULL);
        last_meal_time[i] = start_time;
        ids[i] = i;
        ++i;
    }
    

    i = 0;    
    // crete threads fisolofos
    while (i < NUM_PHILOSOPHERS)
    {
        printf("criação do par --->%d\n", i);
        pthread_create(&philos[i], NULL, philosopher, &ids[i]);
        i += 2;
    }
    usleep(250);
    i = 1;    
    while (i < NUM_PHILOSOPHERS)
    {
        pthread_create(&philos[i], NULL, philosopher, &ids[i]);
        i += 2;
    }

    i = 0;
    while (i < NUM_PHILOSOPHERS)
    {
        pthread_join(philos[i], NULL);
        ++i;
    }
    pthread_join(watcher, NULL);

    i = 0;    
    // libera a memória alocada e destrói os mutexes
    while (i < NUM_PHILOSOPHERS)
    {
        pthread_mutex_destroy(&forks[i]);
        ++i;
    }

    free(forks);
    free(last_meal_time);
    free(philos);
    free(ids);
    
    printf("Simulação finalizada com sucesso\n");
    return (0);
}
