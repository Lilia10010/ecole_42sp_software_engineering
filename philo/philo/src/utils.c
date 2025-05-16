/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:06:42 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/15 23:28:33 by lpaula-n         ###   ########.fr       */
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

const char	*get_state_message(t_State state)
{	
	static const char	*msg[] = {
	[THINKING] = "is thinking",
	[EATING] = "is eating",
	[SLEEPING] = "is sleeping",
	[LEFT_FORK] = "has taken a fork",
	[RIGTH_FORK] = "has taken a fork",
	[DEAD] = "died"
	};

	if (state < 0 || state > DEAD)
		return ("unknown state");
	return (msg[state]);
}

suseconds_t	ft_atol(const char *n)
{
	char		sign;
	suseconds_t	result;

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
	pthread_mutex_lock(&ctx->running_lock);
	if (!ctx->running)
	{
		pthread_mutex_unlock(&ctx->running_lock);
		return ;
	}
	pthread_mutex_unlock(&ctx->running_lock);
	pthread_mutex_lock(&ctx->print_logs_lock);
	if (ctx->running)
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
