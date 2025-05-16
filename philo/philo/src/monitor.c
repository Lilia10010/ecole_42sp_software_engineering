/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:57:58 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/15 23:52:25 by lpaula-n         ###   ########.fr       */
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
				print_logs(DEAD, ctx, &ctx->philosophers[i]);
				pthread_mutex_lock(&ctx->running_lock);
				ctx->running = 0;
				pthread_mutex_unlock(&ctx->running_lock);
				pthread_mutex_unlock(&ctx->last_meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&ctx->last_meal_lock);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
