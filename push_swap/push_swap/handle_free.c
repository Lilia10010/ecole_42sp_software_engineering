/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:09:57 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/22 12:49:41 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int i;

	i = 0;
	if(!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		++i;
	}
	free(args);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if(!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->data = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_node **a)
{
	free_stack(a);
	write(2, "\033[31m", 5);
    write(1, "Error", 5);
    write(2, "\033[0m\n", 5);
	exit(1);
}