#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_PHILOSOPHERS 2  // Você pode ajustar para qualquer número
#define SLEEP_PHILO 100000
#define EAT_PHILO 100000
#define DIE_PHILO 2000

pthread_mutex_t *forks;     // array dinâmico de mutexes para os garfos
pthread_mutex_t dining_mutex = PTHREAD_MUTEX_INITIALIZER; // mutex para garantir que apenas um filósofo come por vez
long *last_meal_time;       // array para rastrear a última refeição de cada filósofo
int running = 1;

long get_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}


void handle_sleep(int id)
{
    printf("%ld ms fisolofo %d está dormindo 🛌 💤\n", get_time_ms(), id);
    usleep(SLEEP_PHILO);
    printf("%ld ms fisolofo %d está pensando 🤔 \n", get_time_ms(), id);
}

void handle_eat(int id)
{
    // Usar mutex para garantir que apenas um filósofo come por vez
    pthread_mutex_lock(&dining_mutex);
    
    last_meal_time[id] = get_time_ms();

    printf("%ld ms fisolofo %d esta comendo 🍝\n", get_time_ms(), id);
    usleep(EAT_PHILO);
    
    pthread_mutex_unlock(&dining_mutex);
}

// Função para pegar os garfos em uma ordem que evite deadlock
void pickup_forks(int id)
{
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;
    
    // Para evitar deadlock: se ID é par, pega primeiro o da esquerda, depois o da direita
    // Se ID é ímpar, pega primeiro o da direita, depois o da esquerda
    if (id % 2 == 0)
    {
        pthread_mutex_lock(&forks[left_fork]);
        printf("%ld ms filósofo %d pegou o garfo esquerdo %d 🍴\n", get_time_ms(), id, left_fork);
       // usleep(100000);  // Pequeno delay para simular tempo de ação
        
        pthread_mutex_lock(&forks[right_fork]);
        printf("%ld ms filósofo %d pegou o garfo direito %d 🍴\n", get_time_ms(), id, right_fork);
    }
    else
    {
        pthread_mutex_lock(&forks[right_fork]);
        printf("%ld ms filósofo %d pegou o garfo direito %d 🍴\n", get_time_ms(), id, right_fork);
       // usleep(100000);  // Pequeno delay para simular tempo de ação
        
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
    
    while (running)
    {
        pickup_forks(id);
        handle_eat(id);
        putdown_forks(id);
       // handle_think(id);
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
            if (now - last_meal_time[i] > DIE_PHILO)  // 1000 ms = 1 segundo 
            {
                printf("%ld ms filósofo %d morreu de fome 💀\n", now, i);
                running = 0;
                exit(1);
            }
            ++i;
        }
        usleep(1000000); // 1s 
    }
    return (NULL);
}

int main(void)
{
    pthread_t *philos;
    pthread_t watcher;
    int *ids;
    long start = get_time_ms();
    int i;
    
    forks = (pthread_mutex_t *)malloc(NUM_PHILOSOPHERS * sizeof(pthread_mutex_t));
    last_meal_time = (long *)malloc(NUM_PHILOSOPHERS * sizeof(long));
    philos = (pthread_t *)malloc(NUM_PHILOSOPHERS * sizeof(pthread_t));
    ids = (int *)malloc(NUM_PHILOSOPHERS * sizeof(int));
    
    if (!forks || !last_meal_time || !philos || !ids) {
        fprintf(stderr, "Erro: falha na alocação de memória\n");
        return 1;
    }

    i = 0;    
    // init mutexes e tempos de refeição
    while (i < NUM_PHILOSOPHERS){
        pthread_mutex_init(&forks[i], NULL);
        last_meal_time[i] = start;
        ids[i] = i;
        ++i;
    }

    i = 0;    
    // crete threads fisolofos
    while (i < NUM_PHILOSOPHERS)
    {
        pthread_create(&philos[i], NULL, philosopher, &ids[i]);
        ++i;
    }
    
    // create thread de monitoramento
    pthread_create(&watcher, NULL, monitor, NULL);

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

    pthread_mutex_destroy(&dining_mutex);
    free(forks);
    free(last_meal_time);
    free(philos);
    free(ids);
    
    printf("Simulação finalizada com sucesso\n");
    return (0);
}
