/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:42:06 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/18 21:07:38 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error_arg(char *arg)
{
	printf("\033[0;31m Invalid argument: %s \n\033[0m", arg);
	return (0);
}

int	parse_must_eat_count(t_Context *ctx, int argc, char **argv)
{
	char	*end_ptr;

	if (argc == 6)
	{
		ctx->must_eat_count = ft_atol(argv[5], &end_ptr);
		if (*end_ptr != '\0' || ctx->must_eat_count <= 0
			|| ctx->must_eat_count > INT_MAX)
			return (print_error_arg(argv[5]));
	}
	else
		ctx->must_eat_count = -1;
	return (1);
}

int	init_args(t_Context *ctx, int argc, char **argv)
{
	char			*end_ptr;
	struct timeval	tv;

	ctx->num_philosophers = ft_atol(argv[1], &end_ptr);
	if (*end_ptr != '\0' || ctx->num_philosophers < 0
		|| ctx->num_philosophers > INT_MAX)
		return (print_error_arg(argv[1]));
	ctx->time_to_die = ft_atol(argv[2], &end_ptr);
	if (*end_ptr != '\0' || ctx->time_to_die < 0 || ctx->time_to_die > INT_MAX)
		return (print_error_arg(argv[2]));
	ctx->time_to_eat = ft_atol(argv[3], &end_ptr);
	if (*end_ptr != '\0' || ctx->time_to_eat < 0
		|| ctx->time_to_eat > INT_MAX)
		return (print_error_arg(argv[3]));
	ctx->time_to_sleep = ft_atol(argv[4], &end_ptr);
	if (*end_ptr != '\0' || ctx->time_to_sleep < 0
		|| ctx->time_to_sleep > INT_MAX)
		return (print_error_arg(argv[4]));
	ctx->running = 1;
	if (!parse_must_eat_count(ctx, argc, argv))
		return (0);
	gettimeofday(&tv, NULL);
	ctx->start_time = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
	return (1);
}

void	init_simulation(t_Context *context)
{
	int	i;

	i = 0;
	pthread_mutex_init(&context->total_meals_lock, NULL);
	pthread_mutex_init(&context->dead_lock, NULL);
	pthread_mutex_init(&context->print_logs_lock, NULL);
	pthread_mutex_init(&context->running_lock, NULL);
	pthread_mutex_init(&context->last_meal_lock, NULL);
	while (i < context->num_philosophers)
	{
		pthread_mutex_init(&context->forks[i], NULL);
		pthread_mutex_init(&context->philosophers[i].meals_eaten_lock, NULL);
		context->philosophers[i].id = i + 1;
		context->philosophers[i].l_fork = &context->forks[i];
		context->philosophers[i].r_fork = &context->forks[(i + 1)
			% context->num_philosophers];
		context->philosophers[i].ctx = context;
		context->philosophers[i].last_meal = get_time_ms(context);
		++i;
	}
}
