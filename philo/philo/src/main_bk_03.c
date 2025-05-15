
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:04:19 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/03 01:25:12 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

const char	*g_state_messase[] = {
	[THINKING]   = "está pensando 🤔",
    [EATING]     = "está comendo 🍝",
    [SLEEPING]   = "está dormindo 🛌 💤",
    [LEFT_FORK]  = "pegou o garfo esquerdo 🍴",
    [RIGTH_FORK] = "pegou o garfo direito 🍴",
    [DEAD]       = "morreu TT 💀"
};

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


// const char	*g_state_messase[] = {
// 	[THINKING]   = "is thinking",
//     [EATING]     = "is eating",
//     [SLEEPING]   = "is sleeping",
//     [LEFT_FORK]  = "has taken a fork",
//     [RIGTH_FORK] = "has taken a fork",
//     [DEAD]       = "died"
// };

long get_time_ms(t_Context *ctx)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L)) - ctx->start_time);
}

void print_logs(t_State state, t_Context *ctx, t_Philo *philo)
{	
	if (!ctx->running)
		return ;
	pthread_mutex_lock(&ctx->print_logs_lock);
	if (ctx->running)
		printf("%ld ms filósofo %d %s\n", get_time_ms(ctx), philo->id, g_state_messase[state]);
	pthread_mutex_unlock(&ctx->print_logs_lock);
}


void handle_sleep(t_Context *ctx, t_Philo *philo)
{
	print_logs(SLEEPING, ctx, philo);
    usleep(ctx->time_to_sleep * 1000);
	print_logs(THINKING, ctx, philo);
    //usleep(50 * 1000);
}

void handle_eat(t_Context *ctx, t_Philo *philo)
{
	pthread_mutex_lock(&ctx->total_meals_lock);
	ctx->total_meals++;
	pthread_mutex_unlock(&ctx->total_meals_lock);
	philo->last_meal = get_time_ms(ctx);
	print_logs(EATING, ctx, philo);
	usleep(ctx->time_to_eat * 1000);
}

void	pickup_forks(t_Context *ctx, t_Philo *philo)
{
	int id;

	id = philo->id;
	if (id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_logs(LEFT_FORK, ctx, philo);
		pthread_mutex_lock(philo->r_fork);
		print_logs(RIGTH_FORK, ctx, philo);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_logs(RIGTH_FORK, ctx, philo);
		pthread_mutex_lock(philo->l_fork);
		print_logs(LEFT_FORK, ctx, philo);
	}
}

void putdown_forks(t_Philo *philo)
{
    int	id;

	id = philo->id;
	if (id % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);		
		pthread_mutex_unlock(philo->r_fork);
	}
	// printf("%ld ms filósofo %d largou os garfos 👐\n", get_time_ms(ctx), id);	
}

void *philosopher(void *arg)
{
    t_Philo		*philo = (t_Philo *)arg;
	t_Context	*ctx = philo->ctx;

	while (ctx->running)
	{
		pickup_forks(ctx, philo);
		handle_eat(ctx, philo);
		putdown_forks(philo);
		handle_sleep(ctx, philo);
	}
	return (NULL);
}

void *ft_monitor(void *arg)
{
    t_Context *ctx = (t_Context *)arg;
    int i;

    while (ctx->running)
    {
        i = 0;
        long now = get_time_ms(ctx);
        while (i < ctx->num_philosophers)
        {
            if (now - ctx->philosophers[i].last_meal > ctx->time_to_die)
            {
                printf("tempo da última refeição: %ld ms (limite: %ld ms)\n",
                    now - ctx->philosophers[i].last_meal, ctx->time_to_die);
                //printf("%ld ms filósofo %d morreu de fome 💀\n", now, ctx->philosophers[i].id);
				print_logs(DEAD, ctx, &ctx->philosophers[i]);
                ctx->running = 0;
                return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}

int main(int argc, char **argv)
{
	t_Context	context;
    pthread_t	monitor;
	int i;

	if (argc != 5)
	{
		printf("Número de argumentos inválidos\n");
		return (1);
	}

	context.num_philosophers = ft_atol(argv[1]);
	context.time_to_die = ft_atol(argv[2]);
	context.time_to_eat = ft_atol(argv[3]);
	context.time_to_sleep = ft_atol(argv[4]);
	context.running = 1;

	// ===> tratar argumentos inválidos

	struct timeval tv;
    gettimeofday(&tv, NULL);
    context.start_time = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);

	//inicializando as threads
	pthread_mutex_init(&context.total_meals_lock, NULL);
	context.total_meals = 0;
	pthread_mutex_init(&context.dead_lock, NULL);
	pthread_mutex_init(&context.print_logs_lock, NULL);
	
	i = 0;
	while (i < context.num_philosophers)
	{
		pthread_mutex_init(&context.forks[i], NULL);
		context.philosophers[i].id = i;
		context.philosophers[i].l_fork = &context.forks[i];
		context.philosophers[i].r_fork = &context.forks[(i + 1) % context.num_philosophers];
		context.philosophers[i].ctx = &context;
		context.philosophers[i].last_meal = get_time_ms(&context);
		++i;		
	}
	pthread_create(&monitor, NULL, ft_monitor, &context);

	i = 0;
	while (i < context.num_philosophers)
	{
		pthread_create(&context.philosophers[i].thread, NULL, philosopher ,&context.philosophers[i]);
		i += 2;
	}
	usleep(250);
	i = 1;
	while (i < context.num_philosophers)
	{
		pthread_create(&context.philosophers[i].thread, NULL, philosopher ,&context.philosophers[i]);
		i += 2;
	}
	pthread_join(monitor, NULL);

	i = 0;
	while (i < context.num_philosophers)
	{
		pthread_join(context.philosophers[i].thread, NULL);
		pthread_mutex_destroy(&context.forks[i]);
		++i;
	}

	printf("Simulação finalizada\n");
	return (0);
}