/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:02:22 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/26 19:52:32 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_node *stack)
{
	int	i;
	int	is_median;

	i = 0;
	if (!stack)
		return ;
	is_median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= is_median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	match;

	while (a)
	{
		match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a->data && current_b->data > match)
			{
				match = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->move_cost = a->index;
		if (!(a->above_median))
			a->move_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->move_cost += a->target_node->index;
		else
			a->move_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->move_cost < cheapest_value)
		{
			cheapest_value = stack->move_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
