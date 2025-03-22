/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:31:51 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/22 14:31:53 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dst, t_node **src, const char *operation)
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
	write(1, operation, 3);
}

/* void	pa(t_node **a, t_node **b, bool print)
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
} */