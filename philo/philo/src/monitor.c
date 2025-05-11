/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:57:58 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/11 17:58:13 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_monitor(void *arg)
{
    int i;
    t_Context *ctx = (t_Context *)arg;

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
                print_logs(DEAD, ctx, &ctx->philosophers[i]);
                ctx->running = 0;
                return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}