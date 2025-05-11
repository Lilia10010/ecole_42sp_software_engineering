/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:22:45 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/11 18:24:55 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *philosopher(void *arg)
{
    t_Philo *philo = (t_Philo *)arg;
    t_Context *ctx = philo->ctx;

    while (ctx->running)
    {
        pickup_forks(ctx, philo);
        handle_eat(ctx, philo);
        putdown_forks(philo);
        handle_sleep(ctx, philo);
    }
    return (NULL);
}

void handle_one_philosopher(t_Context *ctx)
{
    printf("0 1 %s\n", g_state_message[LEFT_FORK]);
    usleep(ctx->time_to_sleep * 1000);
    printf("\033[0;31m%ld 1  %s\033[0m\n", get_time_ms(ctx), g_state_message[DEAD]);
}

void create_philo_threads(t_Context *ctx)
{
    int i;

    i = 0;
    while (i < ctx->num_philosophers)
    {
        pthread_create(&ctx->philosophers[i].thread, NULL, philosopher, &ctx->philosophers[i]);
        i += 2;
    }
    usleep(250);
    i = 1;
    while (i < ctx->num_philosophers)
    {
        pthread_create(&ctx->philosophers[i].thread, NULL, philosopher, &ctx->philosophers[i]);
        i += 2;
    }
}
