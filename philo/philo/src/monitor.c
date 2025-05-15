/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:57:58 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/14 23:47:21 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *arg)
{
	int			i;
	long		now;
	t_Context	*ctx;
	int			is_running;

	ctx = (t_Context *)arg;
	while (1)
	{
		pthread_mutex_lock(&ctx->running_lock);
		is_running = ctx->running;
		pthread_mutex_unlock(&ctx->running_lock);
		if (!is_running)
			break ;
		now = get_time_ms(ctx);
		i = 0;
		while (i < ctx->num_philosophers)
		{
			pthread_mutex_lock(&ctx->last_meal_lock);
			if (now - ctx->philosophers[i].last_meal > ctx->time_to_die)
			{
				pthread_mutex_unlock(&ctx->last_meal_lock);
				print_logs(DEAD, ctx, &ctx->philosophers[i]);
				pthread_mutex_lock(&ctx->running_lock);
				ctx->running = 0;
				pthread_mutex_unlock(&ctx->running_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&ctx->last_meal_lock);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
