
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

#include "philo.h"

// pthread_mutex_t forks[NUM_PHILOSOPHERS];
// long last_meal_time[NUM_PHILOSOPHERS];
// int running = 1;
// long start_time;

long get_time_ms(t_Context *ctx)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L)) - ctx->start_time;
}

void handle_sleep(t_Context *ctx, int id)
{
    printf("%ld ms filósofo %d está dormindo 🛌 💤\n", get_time_ms(ctx), id);
    usleep(ctx->time_to_sleep * 1000);
    printf("%ld ms filósofo %d está pensando 🤔 \n", get_time_ms(ctx), id);
    usleep(50 * 1000);
}

void handle_eat(t_Context *ctx, t_Philo *philo)
{
    static int count = 1;

    philo->last_meal = get_time_ms(ctx);
    printf("%ld ms filósofo %d está comendo 🍝 [%d]\n", get_time_ms(ctx), philo->id, count++);
    usleep(ctx->time_to_eat * 1000);
}

void pickup_forks(t_Context *ctx, t_Philo *philo)
{
    int id = philo->id;
    if (id % 2 == 0)
    {
        pthread_mutex_lock(philo->l_fork);
        printf("%ld ms filósofo %d pegou o garfo esquerdo 🍴\n", get_time_ms(ctx), id);
        pthread_mutex_lock(philo->r_fork);
        printf("%ld ms filósofo %d pegou o garfo direito 🍴\n", get_time_ms(ctx), id);
    }
    else
    {
        pthread_mutex_lock(philo->r_fork);
        printf("%ld ms filósofo %d pegou o garfo direito 🍴\n", get_time_ms(ctx), id);
        pthread_mutex_lock(philo->l_fork);
        printf("%ld ms filósofo %d pegou o garfo esquerdo 🍴\n", get_time_ms(ctx), id);
    }
}

void putdown_forks(t_Context *ctx, t_Philo *philo)
{
    int id = philo->id;
    if (id % 2 == 0)
    {
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
    }
    else
    {
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
    }
    printf("%ld ms filósofo %d largou os garfos 👐\n", get_time_ms(ctx), id);
}

void *philosopher(void *arg)
{
    t_Philo *philo = (t_Philo *)arg;
    t_Context *ctx = philo->ctx;

    while (ctx->running)
    {
        pickup_forks(ctx, philo);
        handle_eat(ctx, philo);
        putdown_forks(ctx, philo);
        handle_sleep(ctx, philo->id);
    }
    return (NULL);
}

void *monitor(void *arg)
{
    t_Context *ctx = (t_Context *)arg;
    int i;

    while (ctx->running)
    {
        i = 0;
        long now = get_time_ms(ctx);
        while (i < ctx->num_philosophers)
        {
            if (now - ctx->philosophers[i].last_meal > ctx->time_to_die)
            {
                printf("tempo da última refeição: %ld ms (limite: %ld ms)\n",
                    now - ctx->philosophers[i].last_meal, ctx->time_to_die);
                printf("%ld ms filósofo %d morreu de fome 💀\n", now, ctx->philosophers[i].id);
                ctx->running = 0;
                return (NULL);
            }
            i++;
        }
        usleep(5000);
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    t_Context context;
    pthread_t monitor_thread;
    int i;

    if (argc != 5)
    {
        printf("Número de argumentos inválido\n");
        return (1);
    }

    context.num_philosophers = ft_atol(argv[1]);
    context.time_to_die = ft_atol(argv[2]);
    context.time_to_eat = ft_atol(argv[3]);
    context.time_to_sleep = ft_atol(argv[4]);
    context.running = 1;

    if (context.num_philosophers < 2 || context.num_philosophers > NUM_PHILOSOPHERS)
    {
        printf("Número de filósofos inválido%li \n", context.time_to_die);
        return (1);
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);
    context.start_time = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);

    i = 0;
    while (i < context.num_philosophers)
    {
        pthread_mutex_init(&context.forks[i], NULL);
        context.philosophers[i].id = i;
        context.philosophers[i].l_fork = &context.forks[i];
        context.philosophers[i].r_fork = &context.forks[(i + 1) % context.num_philosophers];
        context.philosophers[i].last_meal = 0;
        context.philosophers[i].total_meals = 0;
        context.philosophers[i].ctx = &context;
        context.philosophers[i].last_meal = get_time_ms(&context);
        i++;
    }

    pthread_create(&monitor_thread, NULL, monitor, &context);

    i = 0;
    while (i < context.num_philosophers)
    {
        pthread_create(&context.philosophers[i].thread, NULL, philosopher, &context.philosophers[i]);
        i += 2;
    }
    usleep(300);
    i = 1;
    while (i < context.num_philosophers)
    {
        pthread_create(&context.philosophers[i].thread, NULL, philosopher, &context.philosophers[i]);
        i += 2;
    }

    pthread_join(monitor_thread, NULL);

    i = 0;
    while (i < context.num_philosophers)
    {
        pthread_join(context.philosophers[i].thread, NULL);
        pthread_mutex_destroy(&context.forks[i]);
        i++;
    }

    printf("Simulação finalizada com sucesso\n");
    return (0);
}