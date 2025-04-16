/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:16 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 21:42:19 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	move_player_up(t_Game *game)
{
	move_player(game, 0, -1);
}

static	void	move_player_down(t_Game *game)
{
	move_player(game, 0, 1);
}

static	void	move_player_left(t_Game *game)
{
	move_player(game, -1, 0);
}

static	void	move_player_right(t_Game *game)
{
	move_player(game, 1, 0);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_Game	*game;

	game = (t_Game *)param;
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
