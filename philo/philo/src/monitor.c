/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:57:58 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/12 00:19:13 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *arg)
{
	int			i;
	long		now;
	t_Context	*ctx;

	ctx = (t_Context *)arg;
	while (1)
	{
		pthread_mutex_lock(&ctx->running_lock);
		if (!ctx->running)
		{
			pthread_mutex_unlock(&ctx->running_lock);
			break ;
		}
		pthread_mutex_unlock(&ctx->running_lock);
		now = get_time_ms(ctx);
		i = 0;
		while (i < ctx->num_philosophers)
		{
			pthread_mutex_lock(&ctx->last_meal_lock);
			if (now - ctx->philosophers[i].last_meal > ctx->time_to_die)
			{
				//printf("tempo da última refeição: %ld ms (limite: %ld ms)\n",
				//	now - ctx->philosophers[i].last_meal, ctx->time_to_die);
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
