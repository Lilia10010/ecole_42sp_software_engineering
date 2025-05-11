/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:02:14 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/11 18:02:24 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void handle_sleep(t_Context *ctx, t_Philo *philo)
{
    print_logs(SLEEPING, ctx, philo);
    usleep(ctx->time_to_sleep * 1000);
    print_logs(THINKING, ctx, philo);
}

void handle_eat(t_Context *ctx, t_Philo *philo)
{
    pthread_mutex_lock(&ctx->total_meals_lock);
    ctx->total_meals++;
    pthread_mutex_unlock(&ctx->total_meals_lock);
    philo->last_meal = get_time_ms(ctx);
    print_logs(EATING, ctx, philo);
    usleep(ctx->time_to_eat * 1000);
}
