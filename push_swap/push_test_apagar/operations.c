/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:18 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:10:21 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	printf("Executing push function\n");
	(void)dst;
	(void)src;
}

static void	rotate(t_node **stack)
{
	printf("Executing rotate function\n");
	(void)stack;
}

static void	rev_rotate(t_node **stack)
{
	printf("Executing rev_rotate function\n");
	(void)stack;
}

void	pa(t_node **a, t_node **b, bool print)
{
	if (print)
		printf("Executing pa function\n");
	push(a, b);
}

void	pb(t_node **b, t_node **a, bool print)
{
	if (print)
		printf("Executing pb function\n");
	push(b, a);
}

void	rra(t_node **a, bool print)
{
	if (print)
		printf("Executing rra function\n");
	rev_rotate(a);
}

void	rrb(t_node **b, bool print)
{
	if (print)
		printf("Executing rrb function\n");
	rev_rotate(b);
}

void	rrr(t_node **a, t_node **b, bool print)
{
	if (print)
		printf("Executing rrr function\n");
	rev_rotate(a);
	rev_rotate(b);
}

void	ra(t_node **a, bool print)
{
	if (print)
		printf("Executing ra function\n");
	rotate(a);
}

void	rb(t_node **b, bool print)
{
	if (print)
		printf("Executing rb function\n");
	rotate(b);
}

void	rr(t_node **a, t_node **b, bool print)
{
	if (print)
		printf("Executing rr function\n");
	rotate(a);
	rotate(b);
}