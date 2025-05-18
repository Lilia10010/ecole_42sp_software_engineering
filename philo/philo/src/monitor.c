/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:57:58 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/18 17:27:39 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_all_meals(t_Context *ctx)
{
	int	i;
	int	all_ate_enough;

	if (ctx->must_eat_count <= 0)
		return (0);

	all_ate_enough = 1;
	i = 0;

	while (i < ctx->num_philosophers)
	{
		pthread_mutex_lock(&ctx->total_meals_lock);
		if (ctx->philosophers[i].meals_eaten < ctx->must_eat_count)
			all_ate_enough = 0;
		pthread_mutex_unlock(&ctx->total_meals_lock);
		i++;
	}
	if (all_ate_enough)
	{
		pthread_mutex_lock(&ctx->running_lock);
		ctx->running = 0;
		pthread_mutex_unlock(&ctx->running_lock);
		return (1);
	}
	return (0);
}

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
		if (check_all_meals(ctx))
			break ;
		usleep(1000);
	}
	return (NULL);
}
