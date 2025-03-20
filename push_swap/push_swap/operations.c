/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:18 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/19 20:38:36 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*move_node; //ponteiro q vamos utilizar p/ armazenar o nó que será movido

	if (!*src)
		return ;
	move_node = *src; //p/ guardar a ref p/ o nó que será movido (topo de src)
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
		move_node->next = *dst;// O nó que estamos empurrando (move_node) agora aponta para o topo de dst
		move_node->next->prev = move_node;// O antigo topo de dst agora tem push_node como anterior (prev)
		*dst = move_node; // Atualizamos dst para que seu topo seja o push_node
	}
}

static void	rotate_first_to_last(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

static void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if(!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}

void	rra(t_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}

void	ra(t_node **a, bool print)
{
	rotate_first_to_last(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, bool print)
{
	rotate_first_to_last(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, bool print)
{
	rotate_first_to_last(a);
	rotate_first_to_last(b);
	if (!print)
		write(1, "rr\n", 3);
}