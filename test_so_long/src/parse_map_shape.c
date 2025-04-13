/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/11 14:24:16 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_shape_and_walls(Game *game)
{
	int	width;
	int	i;
	int	j;

	width = ft_strlen(game->map.map[0]);
	i = 0;
	game->map.width = width;
	while (i < game->map.height)
	{
		if ((int)ft_strlen(game->map.map[i]) != width)
			return (0); // linhas com tamanhos diferentes
		if (i == 0 || i == game->map.height - 1)
		{
			j = 0;
			while (j < width)
			{
				if (game->map.map[i][j] != '1')
					return (0);
				++j;
			}
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
