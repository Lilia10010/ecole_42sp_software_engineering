/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 22:47:19 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	bool	is_valid_filename(const char *filename)
{
	int	len;

	len = 0;
	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (false);
	return (true);
}

static	int	count_map_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

static	char	**read_map_lines(const char *filename, int *height)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	*height = count_map_lines(filename);
	map = malloc(sizeof(char *) * (*height + 1));
	if (!map || *height <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

bool	parse_map(t_Game *game, const char *filename)
{
	int	height;
	int	fd;

	if (!is_valid_filename(filename))
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	game->map.map = read_map_lines(filename, &height);
	if (!game->map.map)
		return (false);
	game->map.height = height;
	if (!check_map_shape_and_walls(game) || !check_map_validity(game)
		|| !check_map_reachability(game))
		return (false);
	return (true);
}
