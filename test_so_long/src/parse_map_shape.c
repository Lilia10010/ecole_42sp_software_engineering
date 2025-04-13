/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 13:45:19 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	is_horizontal_wall(char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[i] != '1')
			return (0);
		++i;
	}
	return (1);
}

int	check_map_shape_and_walls(Game *game)
{
	int	width;
	int	i;

	width = ft_strlen(game->map.map[0]);
	i = 0;
	game->map.width = width;
	while (i < game->map.height)
	{
		if ((int)ft_strlen(game->map.map[i]) != width)
			return (0);
		if (i == 0 || i == game->map.height - 1)
		{
			if (!is_horizontal_wall(game->map.map[i], width))
				return (0);
		}
		else
		{
			if (game->map.map[i][0] != '1' ||
					game->map.map[i][width - 1] != '1')
				return (0);
		}
		++i;
	}
	return (1);
}
