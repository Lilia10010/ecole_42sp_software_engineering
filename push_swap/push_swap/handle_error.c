/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:09:21 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 00:09:26 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	if (!str || !*str)
		return (1);
	if (*str == '+' || *str == '-')
	{
		++str;
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	while (*str)
	{
		if(!(*str >= '0' && *str <= '9'))
			return (1);
		++str;
	}
	return (0);
}

int	error_duplicate(t_node *a, int n)
{
	while (a)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}