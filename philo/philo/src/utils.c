/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:06:42 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/18 19:24:28 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_end_ptr(const char *str, char **end_ptr)
{
	if (end_ptr)
		*end_ptr = (char *)str;
}

suseconds_t	ft_atol(const char *str, char **end_ptr)
{
	char		sign;
	suseconds_t	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	ft_end_ptr(str, end_ptr);
	return (result * sign);
}

void	destroy_mutexes(t_Context *ctx)
{
	int	i;

	pthread_mutex_lock(&ctx->running_lock);
	ctx->running = 0;
	pthread_mutex_unlock(&ctx->running_lock);
	usleep(1000);
	i = 0;
	while (i < ctx->num_philosophers)
	{
		pthread_mutex_destroy(&ctx->forks[i]);
		pthread_mutex_init(&ctx->philosophers[i].meals_eaten_lock, NULL);
		++i;
	}
	pthread_mutex_destroy(&ctx->total_meals_lock);
	pthread_mutex_destroy(&ctx->dead_lock);
	pthread_mutex_destroy(&ctx->print_logs_lock);
	pthread_mutex_destroy(&ctx->running_lock);
	pthread_mutex_destroy(&ctx->last_meal_lock);
}

long	get_time_ms(t_Context *ctx)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L)) - ctx->start_time);
}

void	print_logs(t_State state, t_Context *ctx, t_Philo *philo)
{
	int	is_running;

	pthread_mutex_lock(&ctx->running_lock);
	is_running = ctx->running;
	pthread_mutex_unlock(&ctx->running_lock);
	if (!is_running && state != DEAD)
		return ;
	pthread_mutex_lock(&ctx->print_logs_lock);
	pthread_mutex_lock(&ctx->running_lock);
	is_running = ctx->running;
	pthread_mutex_unlock(&ctx->running_lock);
	if (is_running || state == DEAD)
	{
		if (state != DEAD)
			printf("%ld %d %s\n", get_time_ms(ctx), philo->id,
				get_state_message(state));
		else
			printf("\033[0;31m%ld %d %s\n\033[0m",
				get_time_ms(ctx), philo->id, get_state_message(state));
	}
	pthread_mutex_unlock(&ctx->print_logs_lock);
}
