/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:02:22 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:10:07 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	current_index(t_node *stack)
{
	if (stack != NULL)
        printf("Índice atual da pilha: %d\n", stack->index);
    else
        printf("Pilha está vazia!\n");

}

static void	set_target_a(t_node *a, t_node *b)
{
	if (a != NULL && b != NULL)
	{
        printf("Configurar alvo A, a->index: %d, b->index: %d\n", a->index, b->index);
	}
    else
	{
        printf("Um ou ambos os nós são nulos!\n");
	}

}

static void	cost_analysis_a(t_node *a, t_node *b)
{
	if (a != NULL && b != NULL)
        printf("Analisando custo de A (%d) e B (%d)\n", a->move_cost, b->move_cost);
    else
        printf("Erro: nós A ou B são nulos!\n");

}

void	set_cheapest(t_node *stack)
{
	if (stack != NULL)
        printf("Configurando o nó mais barato com valor: %d\n", stack->data);
    else
        printf("Pilha está vazia, não é possível configurar!\n");
}

void	init_nodes_a(t_node *a, t_node *b)
{
	if (a != NULL && b != NULL)
	{
        printf("Inicializando nós A (%d) e B (%d)\n", a->index, b->index);
	}
    else
	{
        printf("Erro ao inicializar nós, um dos nós é nulo!\n");
	}
	cost_analysis_a(a, b);
	 set_target_a(a, b);

}