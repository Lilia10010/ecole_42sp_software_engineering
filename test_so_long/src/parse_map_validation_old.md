/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/11 18:19:42 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_validity(Game *game)
{
	char	tile;
	int		has_player;
	int		has_exit;
	int		i;
	int		j;

	has_player = 0;
	has_exit = 0;
	i = 0;
	game->map.total_collectibles = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			tile = game->map.map[i][j];
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
			++j;
		}
		++i;
	}
	return (has_player == 1 && has_exit == 1
		&& game->map.total_collectibles > 0);
}
