/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:06:42 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/11 18:31:08 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// const char	*g_state_messase[] = {
// 	[THINKING]   = "está pensando 🤔",
//     [EATING]     = "está comendo 🍝",
//     [SLEEPING]   = "está dormindo 🛌 💤",
//     [LEFT_FORK]  = "pegou o garfo esquerdo 🍴",
//     [RIGTH_FORK] = "pegou o garfo direito 🍴",
//     [DEAD]       = "morreu TT 💀"
// };

const char *g_state_message[] = {
	[THINKING] = "is thinking",
	[EATING] = "is eating",
	[SLEEPING] = "is sleeping",
	[LEFT_FORK] = "has taken a fork",
	[RIGTH_FORK] = "has taken a fork",
	[DEAD] = "died"};

suseconds_t ft_atol(const char *n)
{
	char sign;
	suseconds_t result;

	sign = 1;
	result = 0;
	while (*n == 32 || (*n >= 9 && *n <= 13))
		++n;
	if (*n == '+' || *n == '-')
	{
		if (*n == '-')
			sign = -1;
		++n;
	}
	while (*n >= '0' && *n <= '9')
	{
		result = result * 10 + (*n - '0');
		++n;
	}
	return (result * sign);
}

void destroy_mutexes(t_Context *ctx)
{
	int i;

	i = 0;
	while (i < ctx->num_philosophers)
	{
		pthread_mutex_destroy(&ctx->forks[i]);
		++i;
	}
	pthread_mutex_destroy(&ctx->total_meals_lock);
	pthread_mutex_destroy(&ctx->dead_lock);
	pthread_mutex_destroy(&ctx->print_logs_lock);
}

long get_time_ms(t_Context *ctx)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L)) - ctx->start_time);
}

void print_logs(t_State state, t_Context *ctx, t_Philo *philo)
{
	if (!ctx->running)
		return;
	pthread_mutex_lock(&ctx->print_logs_lock);
	if (ctx->running)
	{
		if (state != DEAD)
			printf("%ld %d %s\n", get_time_ms(ctx), philo->id, g_state_message[state]);
		else
			printf("\033[0;31m%ld %d %s\n\033[0m", get_time_ms(ctx), philo->id, g_state_message[state]);
	}
	pthread_mutex_unlock(&ctx->print_logs_lock);
}
