/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:16 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/08 18:02:39 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void move_player(Game *game, int dx, int dy)
{
	int new_x = game->player.position_x + dx;
	int new_y = game->player.position_y + dy;

	// Checagem de borda e parede
	if (new_y < 0 || new_y >= game->map.height || new_x < 0 || new_x >= game->map.width)
		return;

	char next_tile = game->map.map[new_y][new_x];

	if (next_tile == WALL)
		return;

	if (next_tile == COLLECTIBLE)
	{
		game->player.collectibles++;
		game->map.map[new_y][new_x] = EMPTY;
		ft_printf("🍇 Coletado! Total: %zu/%zu\n", game->player.collectibles, game->map.total_collectibles);
	}

	if (next_tile == EXIT)
	{
		if (game->player.collectibles == game->map.total_collectibles)
		{
			ft_printf("🚪 Saída alcançada! Movimentos: %zu\n", game->player.moves + 1);
			printf("Movimentos: %zu\n", game->player.moves);
			printf("Coletáveis: %zu/%zi\n", game->player.collectibles, game->map.total_collectibles);
			ft_printf("🚶‍♂️ Movimentos: %d\n", (int)game->player.moves);
ft_printf("🍇 Coletado! Total: %d/%d\n",
	(int)game->player.collectibles,
	(int)game->map.total_collectibles);


			mlx_close_window(game->mlx);
			return;
		}
		else
		{
			ft_printf("⚠️ Você ainda não coletou todos os itens!\n");
			return;
		}
	}

	// Atualiza posição do player
	game->map.map[game->player.position_y][game->player.position_x] = EMPTY;
	game->map.map[new_y][new_x] = PLAYER;
	game->player.position_x = new_x;
	game->player.position_y = new_y;
	game->player.moves++;

	ft_printf("🚶‍♂️ Movimentos: %zu\n", game->player.moves);

	// Atualiza o mapa
	render_map(game);
}



static void move_player_up(Game *game)
{
	move_player(game, 0, -1);
}

static void move_player_down(Game *game)
{
	move_player(game, 0, 1);
}

static void move_player_left(Game *game)
{
	move_player(game, -1, 0);
}

static void move_player_right(Game *game)
{
	move_player(game, 1, 0);
}

static void check_exit(Game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

void my_loop_hook_move(void *param)
{
	Game *game = (Game *)param;

	check_exit(game);
	
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_player_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_player_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) || mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_player_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_player_right(game);
}
