/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:02:14 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/18 21:34:40 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_sleep(t_Context *ctx, t_Philo *philo)
{
	int	is_running;

	print_logs(SLEEPING, ctx, philo);
	usleep(ctx->time_to_sleep * 1000);
	pthread_mutex_lock(&ctx->running_lock);
	is_running = ctx->running;
	pthread_mutex_unlock(&ctx->running_lock);
	if (is_running)
	{
		print_logs(THINKING, ctx, philo);
		usleep(1000);
	}
}

void	handle_eat(t_Context *ctx, t_Philo *philo)
{
	int	is_running;

	pthread_mutex_lock(&ctx->running_lock);
	is_running = ctx->running;
	pthread_mutex_unlock(&ctx->running_lock);
	if (!is_running)
		return ;
	pthread_mutex_lock(&ctx->last_meal_lock);
	philo->last_meal = get_time_ms(ctx);
	pthread_mutex_unlock(&ctx->last_meal_lock);
	print_logs(EATING, ctx, philo);
	usleep(ctx->time_to_eat * 1000);
	pthread_mutex_lock(&philo->meals_eaten_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_lock);
}
