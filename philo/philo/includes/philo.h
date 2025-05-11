/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:45:48 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/11 18:25:40 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_PHILOSOPHERS 500
// # define SLEEP_PHILO 200
// # define EAT_PHILO 200
// # define DIE_PHILO 700

typedef enum e_state
{
    THINKING,
    EATING,
    SLEEPING,
    LEFT_FORK,
    RIGTH_FORK,
    DEAD
} t_State;

// DEAD = '\033[0;91mdied\033[0m'

typedef struct s_philo
{
    int id;
    pthread_t thread;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    // pthread_mutex_t last_meal_mutex;
    long last_meal;
    t_State state;
    struct s_context *ctx;
    // pthread_mutex_t *meal_lock; //proteger o número de refeições e a última refeição
} t_Philo;

typedef struct s_context
{
    int running;
    int num_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    t_Philo philosophers[NUM_PHILOSOPHERS];
    pthread_mutex_t forks[NUM_PHILOSOPHERS];
    long start_time;
    pthread_mutex_t dead_lock;
    pthread_mutex_t print_logs_lock;
    pthread_mutex_t total_meals_lock;
    int total_meals;
    // int				limit_meals;
} t_Context;

suseconds_t ft_atol(const char *n);
int init_args(t_Context *ctx, int argc, char **argv);
void init_simulation(t_Context *context);
void *ft_monitor(void *arg);
void pickup_forks(t_Context *ctx, t_Philo *philo);
void putdown_forks(t_Philo *philo);
void handle_sleep(t_Context *ctx, t_Philo *philo);
void handle_eat(t_Context *ctx, t_Philo *philo);
void destroy_mutexes(t_Context *ctx);
long get_time_ms(t_Context *ctx);
void print_logs(t_State state, t_Context *ctx, t_Philo *philo);
void handle_one_philosopher(t_Context *ctx);
void create_philo_threads(t_Context *ctx);

extern const char *g_state_message[];

void print_logs(t_State state, t_Context *ctx, t_Philo *philo);

#endif