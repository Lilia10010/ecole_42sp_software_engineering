/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:57:58 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/18 21:35:36 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_all_meals(t_Context *ctx)
{
	int	i;
	int	all_ate_enough;

	if (ctx->must_eat_count <= 0)
		return (0);
	all_ate_enough = 1;
	i = 0;
	while (i < ctx->num_philosophers)
	{
		pthread_mutex_lock(&ctx->philosophers[i].meals_eaten_lock);
		if (ctx->philosophers[i].meals_eaten < ctx->must_eat_count)
			all_ate_enough = 0;
		pthread_mutex_unlock(&ctx->philosophers[i].meals_eaten_lock);
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

static	int	check_any_philo_dead(t_Context *ctx)
{
	int			i;
	long		now;

	now = get_time_ms(ctx);
	i = 0;
	while (i < ctx->num_philosophers)
	{
		pthread_mutex_lock(&ctx->last_meal_lock);
		if (now - ctx->philosophers[i].last_meal > ctx->time_to_die)
		{
			pthread_mutex_lock(&ctx->running_lock);
			ctx->running = 0;
			pthread_mutex_unlock(&ctx->running_lock);
			print_logs(DEAD, ctx, &ctx->philosophers[i]);
			pthread_mutex_unlock(&ctx->last_meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&ctx->last_meal_lock);
		i++;
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
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
		if (check_any_philo_dead(ctx))
			return (NULL);
		if (check_all_meals(ctx))
			break ;
		usleep(1000);
	}
	return (NULL);
}
