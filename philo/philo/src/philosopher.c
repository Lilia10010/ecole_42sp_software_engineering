/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:22:45 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/14 23:47:21 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher(void *arg)
{
	t_Philo		*philo;
	t_Context	*ctx;

	int can_continue ;
	philo = (t_Philo *)arg;
	ctx = philo->ctx;
	while (1)
	{
		pthread_mutex_lock(&ctx->running_lock);
		can_continue = ctx->running;
		pthread_mutex_unlock(&ctx->running_lock);
		if (!can_continue)
			break ;
		pickup_forks(ctx, philo);
		pthread_mutex_lock(&ctx->running_lock);
		can_continue = ctx->running;
		pthread_mutex_unlock(&ctx->running_lock);
		if (!can_continue)
		{
			putdown_forks(philo);
			break ;
		}
		handle_eat(ctx, philo);
		putdown_forks(philo);
		pthread_mutex_lock(&ctx->running_lock);
		can_continue = ctx->running;
		pthread_mutex_unlock(&ctx->running_lock);
		if (!can_continue)
			break ;
		handle_sleep(ctx, philo);
	}
	return (NULL);
}

void	handle_one_philosopher(t_Context *ctx)
{
	printf("0 1 %s\n", get_state_message(LEFT_FORK));
	usleep(ctx->time_to_sleep * 1000);
	printf("\033[0;31m%ld 1  %s\033[0m\n", get_time_ms(ctx),
		get_state_message(DEAD));
}

void	create_philo_threads(t_Context *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_philosophers)
	{
		pthread_create(&ctx->philosophers[i].thread, NULL, philosopher,
			&ctx->philosophers[i]);
		i += 2;
	}
	usleep(250);
	i = 1;
	while (i < ctx->num_philosophers)
	{
		pthread_create(&ctx->philosophers[i].thread, NULL, philosopher,
			&ctx->philosophers[i]);
		i += 2;
	}
}
