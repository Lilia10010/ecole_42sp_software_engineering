/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:52 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:10:53 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_node **a, char **args)
{
	(void)a;
	printf("init_stack");
	while (*args)
	{
		printf("%s", *args);
		++args;
	}
	printf("\n");
}

static long	ft_atol(const char *s)
{
	printf("Executing ft_atol function with input: %s\n", s);
	return (0);
}

static void	append_node(t_node **stack, int n)
{
	printf("Executing append_node function with value: %d\n", n);
	(void)stack;
}


t_node	*get_cheapest(t_node *stack)
{
	printf("Executing get_cheapest function\n");
	(void)stack;
	return (NULL);
}

void	prep_for_push(t_node **stack,
						t_node *top_node,
						char stack_name)
{
	printf("Executing prep_for_push on stack: %c with top node value: %d\n",
		stack_name, top_node ? top_node->data : -1);
	(void)stack;
	
}