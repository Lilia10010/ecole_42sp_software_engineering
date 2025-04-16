/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:13:15 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/10/29 21:20:24 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_length;
	char	*dest;
	int		i;

	if (!s || !f)
		return (NULL);
	s_length = ft_strlen(s);
	dest = malloc(sizeof(char) *(s_length + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
