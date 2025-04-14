/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:02:01 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 21:43:16 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_tile(char tile, t_Game *game, int i, int j)
{
	if (tile == 'P')
	{
		game->player.position_x = j;
		game->player.position_y = i;
		return (1);
	}
	else if (tile == 'E')
	{
		game->map.exit_x = j;
		game->map.exit_y = i;
		return (2);
	}
	else if (tile == 'C')
	{
		game->map.total_collectibles++;
		return (3);
	}
	else if (tile != '1' && tile != '0')
		return (0);
	return (4);
}

void	process_result(int result, int *has_player, int *has_exit, int *valid)
{
	if (result == 1)
		(*has_player)++;
	else if (result == 2)
		(*has_exit)++;
	else if (result == 0)
		*valid = 0;
}

int	check_map_validity(t_Game *game)
{
	int	has_player;
	int	has_exit;
	int	i;
	int	valid;
	int	j;

	has_player = 0;
	has_exit = 0;
	i = 0;
	valid = 1;
	game->map.total_collectibles = 0;
	while (i < game->map.height && valid)
	{
		j = 0;
		while (j < game->map.width && valid)
		{
			process_result(is_valid_tile(game->map.map[i][j], game, i, j),
				&has_player, &has_exit, &valid);
			j++;
		}
		i++;
	}
	return (valid && has_player == 1 && has_exit == 1
		&& game->map.total_collectibles > 0);
}
