/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:20:11 by alexanfe          #+#    #+#             */
/*   Updated: 2024/11/04 00:00:34 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_length;

	little_length = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (little_length > len)
		return (NULL);
	while (*big && len >= little_length)
	{
		if (ft_strncmp(big, little, little_length) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
