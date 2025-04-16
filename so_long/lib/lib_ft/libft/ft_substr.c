/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:08:28 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/03 04:45:09 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	alloc_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	alloc_len = s_len - start;
	if (alloc_len > len)
		alloc_len = len;
	substr = malloc(alloc_len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, alloc_len + 1);
	return (substr);
}
