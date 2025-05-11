/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:59:44 by microbiana        #+#    #+#             */
/*   Updated: 2025/05/11 18:00:15 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void pickup_forks(t_Context *ctx, t_Philo *philo)
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
    int id;

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
}
