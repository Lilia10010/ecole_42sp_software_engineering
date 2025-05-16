/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:22:45 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/15 23:44:33 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_simulation_running(t_Context *ctx)
{
	int	is_running;

	pthread_mutex_lock(&ctx->running_lock);
	is_running = ctx->running;
	pthread_mutex_unlock(&ctx->running_lock);
	return (is_running);
}

static void	*philosopher(void *arg)
{
	t_Philo		*philo;
	t_Context	*ctx;
	int 		is_running;

	philo = (t_Philo *)arg;
	ctx = philo->ctx;
	// while (1)
	// {
	// 	pthread_mutex_lock(&ctx->running_lock);
	// 	is_running = ctx->running;
	// 	pthread_mutex_unlock(&ctx->running_lock);
	// 	if (!is_running)
	// 		break ;
	// 	pickup_forks(ctx, philo);
	// 	pthread_mutex_lock(&ctx->running_lock);
	// 	is_running = ctx->running;
	// 	pthread_mutex_unlock(&ctx->running_lock);
	// 	if (!is_running)
	// 	{
	// 		putdown_forks(philo);
	// 		break ;
	// 	}
	// 	handle_eat(ctx, philo);
	// 	putdown_forks(philo);
	// 	pthread_mutex_lock(&ctx->running_lock);
	// 	is_running = ctx->running;
	// 	pthread_mutex_unlock(&ctx->running_lock);
	// 	if (!is_running)
	// 		break ;
	// 	handle_sleep(ctx, philo);
	// }
	while (1)
{
	if (!is_simulation_running(ctx))
		break;

	pickup_forks(ctx, philo);

	if (!is_simulation_running(ctx))
	{
		putdown_forks(philo);
		break;
	}

	handle_eat(ctx, philo);
	putdown_forks(philo);

	if (!is_simulation_running(ctx))
		break;

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
