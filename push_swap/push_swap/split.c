/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:48 by microbiana        #+#    #+#             */
/*   Updated: 2025/03/18 12:17:01 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_next_word(char *str, char delimiter)
{
	static int	cursor = 0;
	char		*next_word;
	int			len_word;
	int			i;

	len_word = 0;
	i = 0;
	while (str[cursor] == delimiter)
		++cursor;
	while ((str[cursor + len_word] != delimiter && str[cursor + len_word]))
		++len_word;
	next_word = malloc((size_t)len_word * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[cursor] != delimiter) && str[cursor])
		next_word[i++] = str[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

static	int 	count_words(char *str, char delimiter)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while(*str == delimiter)
			++str;
		while (*str != delimiter && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

char	**split(char *str,  char delimiter)
{
	int		word_count;
	char	**result;
	int 	i;

	i = 0;
	word_count = count_words(str, delimiter);
	if (!word_count)
		exit(1);
	result = (char **)malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!result)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			result[i] = (char *)malloc(sizeof(char));
			if (!result)
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(str,  delimiter);
	}
	result[i] = NULL;
	return (result);
}
