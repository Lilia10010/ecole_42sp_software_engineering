/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:24 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/22 13:47:13 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_split_result(char **split_array)
{
    if (!split_array)
    {
        printf("(null)\n");
        return;
    }
    
    printf("=== Split Result ===\n");
	int i;
    for (i = 0; split_array[i]; i++)
    {
        printf("[%d]: \"%s\"\n", i, split_array[i]);
    }
    printf("[%d]: %s\n", (int)(split_array[i] ? i : -1), "(null) (end marker)");
    printf("====================\n");
}

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
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	init_stack_a(&a, args + 1);
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

