/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:45:48 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/03 01:23:44 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_PHILOSOPHERS 5
#define SLEEP_PHILO 200	
#define EAT_PHILO 200
#define DIE_PHILO 500

typedef enum e_state
{
    THINKING = 'is thinking',
    EATING = 'is eating',
    SLEEPING = 'is sleeping',
    LEFT_FORK = 'has take a fork',
    RIGTH_FORK = 'has take a fork',
    DEAD = '\033[0;91mdied\033[0m'
} t_State;

typedef struct s_philo
{
    int             id;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    long            last_meal;
    int             total_meals;
    t_State         state;
    //pthread_mutex_t *meal_lock; //proteger o número de refeições e a última refeição
} t_Philo;

typedef struct s_context
{
    int     num_philosophers;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    t_Philo *philosophers;
    long    start_time;
} t_Context;

#endif