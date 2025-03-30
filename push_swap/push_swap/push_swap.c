/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:24 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/30 20:38:53 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	args = argv + 1;

	init_stack_a(&a, args);
	if (!is_sorted_ascending(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack_with_aux(&a, &b);
	}
	free_stack(&a);
	if (argc == 2 && args != argv + 1)
		free_args(args);
	return (0);
}
