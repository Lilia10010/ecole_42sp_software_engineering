/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:10 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:10:12 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_node *a, t_node *b)
{
	 if (a != NULL && b != NULL)
        printf("Configurando alvo B, a->index: %d, b->index: %d\n", a->index, b->index);
    else
        printf("Erro: Um ou ambos os nós são nulos!\n");
}

void	init_nodes_b(t_node *a, t_node *b)
{
	if (a != NULL && b != NULL)
    {
        printf("Inicializando nós B com os seguintes índices:\n");
        printf("  Nó A - index: %d\n", a->index);
        printf("  Nó B - index: %d\n", b->index);
    }
    else
    {
        printf("Erro ao inicializar nós B, um ou ambos os nós são nulos!\n");
    }
	set_target_b(a, b);
}