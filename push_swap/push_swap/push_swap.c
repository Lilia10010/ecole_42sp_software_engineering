/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:24 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/19 21:39:00 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**args; //para não sobreescreverr o argv

	a = NULL;
	b =	NULL;
	if(argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		args = split(argv[1], ' ');
	else
		args = argv + 1;
	init_stack_a(&a, args);
	if(!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack_with_aux(&a, &b);
	}
	free_stack(&a);
	if (argc == 2)
		free_args(args);
	return (0);
}

