/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:31:30 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:46:44 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle_read_error(char *remainder)
{
	free(remainder);
	return (NULL);
}

static char	*read_file(int fd, char *buffer, char *remainder)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	if (!remainder)
	{
		remainder = ft_strdup_gnl("");
		if (!remainder)
			return (NULL);
	}
	while (!ft_strchr_gnl(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (handle_read_error(remainder));
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(remainder, buffer);
		free(remainder);
		remainder = temp;
		if (!remainder)
			return (NULL);
	}
	return (remainder);
}

static char	*get_line(char *remainder)
{
	int		i;
	char	*line;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		line = ft_substr_gnl(remainder, 0, i + 1);
	else
		line = ft_substr_gnl(remainder, 0, i);
	return (line);
}

static char	*update_remainder(char *remainder)
{
	int		i;
	char	*temp;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
		return (handle_read_error(remainder));
	temp = ft_substr_gnl(remainder, i + 1, ft_strlen_gnl(remainder) - i);
	free(remainder);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_file(fd, buffer, remainder);
	if (!remainder)
		return (NULL);
	line = get_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
