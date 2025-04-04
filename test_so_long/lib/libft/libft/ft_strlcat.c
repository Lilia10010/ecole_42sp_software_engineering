/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:52:30 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/03 00:09:13 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] && dest_length < size)
		dest_length++;
	while (src[src_length] && (dest_length + src_length + 1) < size)
	{
		dest[dest_length + src_length] = src[src_length];
		src_length++;
	}
	if (dest_length < size)
		dest[dest_length + src_length] = '\0';
	return (dest_length + ft_strlen (src));
}
