/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:22:45 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/14 22:59:20 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	*philosopher(void *arg)
// {
// 	t_Philo		*philo;
// 	t_Context	*ctx;

// 	philo = (t_Philo *)arg;
// 	ctx = philo->ctx;
// 	pthread_mutex_lock(&ctx->running_lock);
// 	while (1)
// 	{
// 		if (!ctx->running)
// 		{
// 			pthread_mutex_unlock(&ctx->running_lock);
// 			break ;
// 		}
// 		pthread_mutex_unlock(&ctx->running_lock);

// 		pickup_forks(ctx, philo);
// 		handle_eat(ctx, philo);
// 		putdown_forks(philo);
// 		handle_sleep(ctx, philo);
// 	}
// 	return (NULL);
// }
static void	*philosopher(void *arg)
{
	t_Philo		*philo;
	t_Context	*ctx;

	philo = (t_Philo *)arg;
	ctx = philo->ctx;
	while (1)
	{
		pthread_mutex_lock(&ctx->running_lock);
		if (!ctx->running)
		{
			pthread_mutex_unlock(&ctx->running_lock);
			break ;
		}
		pthread_mutex_unlock(&ctx->running_lock);

		pickup_forks(ctx, philo);

		pthread_mutex_lock(&ctx->running_lock);
		if (!ctx->running)
		{
			pthread_mutex_unlock(&ctx->running_lock);
			break ;
		}
		pthread_mutex_unlock(&ctx->running_lock);

		handle_eat(ctx, philo);
		
		putdown_forks(philo);

		pthread_mutex_lock(&ctx->running_lock);
		if (!ctx->running)
		{
			pthread_mutex_unlock(&ctx->running_lock);
			break ;
		}
		pthread_mutex_unlock(&ctx->running_lock);

		handle_sleep(ctx, philo);
	}
	return (NULL);
}


void	handle_one_philosopher(t_Context *ctx)
{
	printf("0 1 %s\n", get_state_message(LEFT_FORK));
	usleep(ctx->time_to_sleep * 1000);
	printf("\033[0;31m%ld 1  %s\033[0m\n",
		get_time_ms(ctx), get_state_message(DEAD));
}

void	create_philo_threads(t_Context *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_philosophers)
	{
		pthread_create(&ctx->philosophers[i].thread,
			NULL, philosopher, &ctx->philosophers[i]);
		i += 2;
	}
	usleep(250);
	i = 1;
	while (i < ctx->num_philosophers)
	{
		pthread_create(&ctx->philosophers[i].thread, NULL,
			philosopher, &ctx->philosophers[i]);
		i += 2;
	}
}
