/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:16 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/11 14:25:41 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	move_player_up(Game *game)
{
	move_player(game, 0, -1);
}

static	void	move_player_down(Game *game)
{
	move_player(game, 0, 1);
}

static	void	move_player_left(Game *game)
{
	move_player(game, -1, 0);
}

static	void	move_player_right(Game *game)
{
	move_player(game, 1, 0);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	Game	*game;

	game = (Game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
		}
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player_up(game);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player_down(game);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player_left(game);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player_right(game);
	}
	check_exit(game);
}
