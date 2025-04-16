/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:31:41 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/03 03:53:03 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const	char *s, int c)
{
	int				length;
	unsigned char	target_char;

	target_char = (unsigned char)c;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == target_char)
		{
			return ((char *) s + length);
		}
		length--;
	}
	if (target_char == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
