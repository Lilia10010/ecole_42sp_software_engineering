/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:39 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:10:40 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
    {
        printf("Pilha não tem três elementos para ordenar.\n");
        return;  // Se a pilha não tiver 3 elementos, não faz nada
    }


        printf("Pilha já está ordenada - mintira sei não.\n");


	 printf("\n");

}