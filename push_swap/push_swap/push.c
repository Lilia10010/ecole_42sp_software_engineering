/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:31:51 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/26 20:31:12 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_node **dst, t_node **src)
{
	t_node	*move_node;

	if (!*src)
		return ;
	move_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	move_node->prev = NULL;
	if (!*dst)
	{
		*dst = move_node;
		move_node->next = NULL;
	}
	else
	{
		move_node->next = *dst;
		move_node->next->prev = move_node;
		*dst = move_node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
