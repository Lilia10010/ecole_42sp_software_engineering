/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:42:06 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/14 22:49:33 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_args(t_Context *ctx, int argc, char **argv)
{
    if (argc != 5)
    {
        printf("Número de argumentos inválidos\n");
        return (0);
    }

    ctx->num_philosophers = ft_atol(argv[1]);
    ctx->time_to_die = ft_atol(argv[2]);
    ctx->time_to_eat = ft_atol(argv[3]);
    ctx->time_to_sleep = ft_atol(argv[4]);
    ctx->running = 1;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    ctx->start_time = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);

    return (1);
}

void init_simulation(t_Context *context)
{
    int i;

    i = 0;
    pthread_mutex_init(&context->total_meals_lock, NULL);
    context->total_meals = 0;
    pthread_mutex_init(&context->dead_lock, NULL);
    pthread_mutex_init(&context->print_logs_lock, NULL);
    pthread_mutex_init(&context->running_lock, NULL);
    pthread_mutex_init(&context->last_meal_lock, NULL);

    while (i < context->num_philosophers)
    {
        pthread_mutex_init(&context->forks[i], NULL);
        context->philosophers[i].id = i + 1;
        context->philosophers[i].l_fork = &context->forks[i];
        context->philosophers[i].r_fork = &context->forks[(i + 1) % context->num_philosophers];
        context->philosophers[i].ctx = context;
        context->philosophers[i].last_meal = get_time_ms(context);
        ++i;
    }
}