/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:10:46 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/03 03:46:45 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	target_char;

	target_char = (unsigned char)c;
	while (*str)
	{
		if (*str == target_char)
		{
			return ((char *)str);
		}
		str++;
	}
	if (target_char == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
