/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:04:19 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/14 23:47:21 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_Context	context;
	pthread_t	monitor;
	int			i;

	if (!init_args(&context, argc, argv))
		return (1);
	if (context.num_philosophers == 1)
	{
		handle_one_philosopher(&context);
		return (0);
	}
	init_simulation(&context);
	pthread_create(&monitor, NULL, ft_monitor, &context);
	create_philo_threads(&context);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < context.num_philosophers)
	{
		pthread_join(context.philosophers[i].thread, NULL);
		++i;
	}
	destroy_mutexes(&context);
	return (0);
}
