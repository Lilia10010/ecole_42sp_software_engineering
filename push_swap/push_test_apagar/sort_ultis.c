/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ultis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:43 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:10:46 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	min_on_top(t_node **a)
{
	printf("Executing min_on_top function\n");
	(void)a;
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	printf("Executing move_b_to_a function\n");
	(void)a;
	(void)b;
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	printf("Executing move_a_to_b function\n");
	(void)a;
	(void)b;
}

static void	rev_rotate_both(t_node **a,
								t_node **b,
								t_node *cheapest_node)
{
	printf("Executing rev_rotate_both function\n");
	(void)a;
	(void)b;
	(void)cheapest_node;
}

static void	rotate_both(t_node **a,
						t_node **b,
						t_node *cheapest_node)
{
	printf("Executing rotate_both function\n");
	(void)a;
	(void)b;
	(void)cheapest_node;	
}

static void example_usage(t_node **a, t_node **b, t_node *cheapest_node)
{
    min_on_top(a);
    move_b_to_a(a, b);
    move_a_to_b(a, b);
    rev_rotate_both(a, b, cheapest_node);
    rotate_both(a, b, cheapest_node);
}