/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:45:48 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/18 21:34:52 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

# define NUM_PHILOSOPHERS 200

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	LEFT_FORK,
	RIGTH_FORK,
	DEAD
}	t_State;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		meals_eaten_lock;
	long				last_meal;
	int					meals_eaten;
	t_State				state;
	struct s_context	*ctx;
}	t_Philo;

typedef struct s_context
{
	int				running;
	int				num_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;
	t_Philo			philosophers[NUM_PHILOSOPHERS];
	pthread_mutex_t	forks[NUM_PHILOSOPHERS];
	long			start_time;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	print_logs_lock;
	pthread_mutex_t	total_meals_lock;
	pthread_mutex_t	running_lock;
	pthread_mutex_t	last_meal_lock;
}	t_Context;

suseconds_t	ft_atol(const char *str, char **end_ptr);
int			init_args(t_Context *ctx, int argc, char **argv);
long		get_time_ms(t_Context *ctx);
void		init_simulation(t_Context *context);
void		*ft_monitor(void *arg);
void		pickup_forks(t_Context *ctx, t_Philo *philo);
void		putdown_forks(t_Philo *philo);
void		handle_sleep(t_Context *ctx, t_Philo *philo);
void		handle_eat(t_Context *ctx, t_Philo *philo);
void		destroy_mutexes(t_Context *ctx);
void		print_logs(t_State state, t_Context *ctx, t_Philo *philo);
void		handle_one_philosopher(t_Context *ctx);
void		create_philo_threads(t_Context *ctx);
void		print_logs(t_State state, t_Context *ctx, t_Philo *philo);
const char	*get_state_message(t_State state);

#endif