/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reachability.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 13:54:40 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	char	**copy_map(char **original, int height)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		++i;
	}
	copy[height] = NULL;
	return (copy);
}

static	void	flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static	bool	has_unreachable_elements(char **map, int height, char target)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

bool	check_map_reachability(Game *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map.map, game->map.height);
	if (!map_copy)
		return (false);
	flood_fill(map_copy, game->player.position_x, game->player.position_y);
	if (has_unreachable_elements(map_copy, game->map.height, 'E'))
	{
		ft_printf("Error: Unreachable exit\n");
		free_map(map_copy, game->map.height);
		return (false);
	}
	if (has_unreachable_elements(map_copy, game->map.height, 'C'))
	{
		ft_printf("Error: Unreachable collectible\n");
		free_map(map_copy, game->map.height);
		return (false);
	}
	free_map(map_copy, game->map.height);
	return (true);
}
