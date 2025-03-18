/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:11:00 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:11:01 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
    if (*head && (*head)->next)
    {
        printf("Trocando os dois primeiros elementos da pilha.\n");
    }
    else
    {
        printf("Não há elementos suficientes para trocar na pilha.\n");
    }

}

void	sa(t_node	**a, bool print)
{
	if (print)
    {
        printf("Operação SA (troca nos dois primeiros elementos de A)\n");
    }
    swap(a);
}

void	sb(t_node **b, bool print)
{
	 if (print)
    {
        printf("Operação SB (troca nos dois primeiros elementos de B)\n");
    }
    swap(b);

}

void	ss(t_node **a, t_node **b, bool print)
{
	if (print)
    {
        printf("Operação SS (troca nos dois primeiros elementos de A e B)\n");
    }
    swap(a);
    swap(b);

}