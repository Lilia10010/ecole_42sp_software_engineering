/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/10 22:59:23 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_map_shape_and_walls(Game *game)
{
	int	width = ft_strlen(game->map.map[0]);
	int	i;

	game->map.width = width;

	for (i = 0; i < game->map.height; i++)
	{
		if ((int)ft_strlen(game->map.map[i]) != width)
			return (0); // linhas com tamanhos diferentes

		if (i == 0 || i == game->map.height - 1)
		{
			for (int j = 0; j < width; j++)
				if (game->map.map[i][j] != '1')
					return (0);
		}
		else
		{
			if (game->map.map[i][0] != '1' || game->map.map[i][width - 1] != '1')
				return (0);
		}
	}
	return (1);
}
