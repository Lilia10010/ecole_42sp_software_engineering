/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/10 23:08:26 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_map_validity(Game *game)
{
	int	has_player = 0;
	int	has_exit = 0;
	int	i, j;

	game->map.total_collectibles = 0;
	for (i = 0; i < game->map.height; i++)
	{
		for (j = 0; j < game->map.width; j++)
		{
			char tile = game->map.map[i][j];
			if (tile == 'P')
			{
				game->player.position_x = j;
				game->player.position_y = i;
				has_player++;
			}
			else if (tile == 'E')
			{
				game->map.exit_x = j;
				game->map.exit_y = i;
				has_exit++;
			}
			else if (tile == 'C')
				game->map.total_collectibles++;
			else if (tile != '1' && tile != '0')
				return (0);
		}
	}
	return (has_player == 1 && has_exit == 1 && game->map.total_collectibles > 0);
}
