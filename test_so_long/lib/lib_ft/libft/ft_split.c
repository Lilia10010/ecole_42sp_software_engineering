/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:37:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/03 21:45:24 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_result(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		++i;
	}
	free(result);
	return (NULL);
}

static size_t	ft_substringlen(const char *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (*s != c)
		{
			++result;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (result);
}

static char	**ft_allocate_result(const char *s, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (ft_substringlen(s, c) + 1));
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;

	i = 0;
	result = ft_allocate_result(s, c);
	if (!s || !result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			result[i] = ft_substr(s - len, 0, len);
			if (!result[i])
				return (free_result(result, i));
			i++;
		}
		else
			++s;
	}
	result[i] = (NULL);
	return (result);
}
