/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:35 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/30 14:20:40 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rotate_both(t_node **a,	t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) \
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	min_on_top(t_node **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack_with_aux(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted_ascending(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted_ascending(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted_ascending(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
