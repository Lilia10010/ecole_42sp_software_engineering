/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:04:19 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/18 21:14:09 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("\033[0;31m Number of invalid arguments [%d args] \n\033[0m", argc);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_Context	context;
	pthread_t	monitor;
	int			i;

	if (!validate_args_count(argc))
		return (0);
	if (!init_args(&context, argc, argv))
		return (1);
	if (context.num_philosophers == 1)
	{
		handle_one_philosopher(&context);
		return (0);
	}
	init_simulation(&context);
	create_philo_threads(&context);
	pthread_create(&monitor, NULL, ft_monitor, &context);
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
