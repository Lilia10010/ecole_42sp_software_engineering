/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_reachability.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:37:15 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/07 21:38:17 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char **copy_map(char **original, int height)
{
	char **copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return NULL;
	for (int i = 0; i < height; i++)
		copy[i] = ft_strdup(original[i]);
	copy[height] = NULL;
	return copy;
}

static void flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	map[y][x] = 'F'; // Marca como visitado
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}


static bool has_unreachable_elements(char **map, int height, char target)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; map[i][j]; j++)
		{
			if (map[i][j] == target)
				return true;
		}
	}
	return false;
}


static bool check_map_reachability(Game *game)
{
	char **map_copy = copy_map(game->map.map, game->map.height);
	if (!map_copy)
		return false;

	flood_fill(map_copy, game->player.x, game->player.y);

	if (has_unreachable_elements(map_copy, game->map.height, 'E'))
	{
		ft_printf("Error: Unreachable exit\n");
		free_map(map_copy, game->map.height);
		return false;
	}
	if (has_unreachable_elements(map_copy, game->map.height, 'C'))
	{
		ft_printf("Error: Unreachable collectible\n");
		free_map(map_copy, game->map.height);
		return false;
	}

	free_map(map_copy, game->map.height);
	return true;
}
