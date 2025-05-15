/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:16 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 21:41:49 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	is_valid_move(t_Game *game, int x, int y)
{
	if (y < 0 || y >= game->map.height || x < 0 || x >= game->map.width)
		return (0);
	if (game->map.map[y][x] == WALL)
		return (0);
	return (1);
}

static	void	handle_collectible(t_Game *game, int x, int y)
{
	game->player.collectibles++;
	game->map.map[y][x] = EMPTY;
	if (game->map.instances[y][x])
	{
		mlx_delete_image(game->mlx, game->map.instances[y][x]);
		game->map.instances[y][x] = NULL;
	}
}

static	int	handle_exit(t_Game *game)
{
	if (game->player.collectibles == game->map.total_collectibles)
	{
		ft_printf("Movies: %i\n", game->player.moves + 1);
		mlx_close_window(game->mlx);
	}
	return (0);
}

static	void	update_player_position(t_Game *game, int new_x, int new_y)
{
	draw_tile(game, EMPTY, game->player.position_x, game->player.position_y);
	game->player.position_x = new_x;
	game->player.position_y = new_y;
	draw_tile(game, PLAYER, new_x, new_y);
	game->map.map[new_y][new_x] = PLAYER;
	game->player.moves++;
	ft_printf("Movies: %i\n", game->player.moves);
}

void	move_player(t_Game *game, int horizontal_move, int vertical_move)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = game->player.position_x + horizontal_move;
	new_y = game->player.position_y + vertical_move;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	next_tile = game->map.map[new_y][new_x];
	if (next_tile == COLLECTIBLE)
		handle_collectible(game, new_x, new_y);
	if (next_tile == EXIT)
		if (!handle_exit(game))
			return ;
	update_player_position(game, new_x, new_y);
}
