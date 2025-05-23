/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:56 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/26 19:54:11 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted_ascending(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		++i;
	}
	return (i);
}

t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;

	min_node = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->data < min_node->data)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;

	max_node = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->data > max_node->data)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
