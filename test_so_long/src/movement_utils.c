/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:16 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/10 22:42:08 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int is_valid_move(Game *game, int x, int y)
{
	if (y < 0 || y >= game->map.height || x < 0 || x >= game->map.width)
		return (0);
	if (game->map.map[y][x] == WALL)
		return (0);
	return (1);


}

static	void	handle_collectible(Game *game, int x, int y)
{
	game->player.collectibles++;
	game->map.map[y][x] = EMPTY;
	if (game->map.instances[y][x])
	{
		mlx_delete_image(game->mlx, game->map.instances[y][x]);
		game->map.instances[y][x] = NULL;
	}
	ft_printf("🍇 Coletando: %i/%i\n", game->player.collectibles, game->map.total_collectibles);

}

static int  handle_exit(Game *game)
{
	if (game->player.collectibles == game->map.total_collectibles)
	{
		ft_printf("\n🍻 Saída alcançada!\n");
		ft_printf("👯 Total de movimentos:%i\n", game->player.moves + 1);
		ft_printf("🍇 Total da coleta: %i/%i\n", game->player.collectibles, game->map.total_collectibles);
		mlx_close_window(game->mlx);
		return (0);
	}
	else
	{
		ft_printf("⚠️ Você ainda não coletou todos os itens!\n");
		return (0);
	}
}

static void update_player_position(Game *game, int new_x, int new_y)
{
	draw_tile(game, EMPTY, game->player.position_x, game->player.position_y);
	game->player.position_x = new_x;
	game->player.position_y = new_y;
	draw_tile(game, PLAYER, new_x, new_y);
	game->map.map[new_y][new_x] = PLAYER;
	game->player.moves++;
	ft_printf("👯 Movimentos: %i\n", game->player.moves);

}

void	move_player(Game *game, int horizontal_move, int vertical_move)
{
	int new_x;
	int new_y;

	new_x = game->player.position_x + horizontal_move;
	new_y = game->player.position_y + vertical_move;
	if (!is_valid_move(game, new_x, new_y))
		return;
	char next_tile;
	next_tile = game->map.map[new_y][new_x];
	if (next_tile == COLLECTIBLE)
		handle_collectible(game, new_x, new_y);

	if (next_tile == EXIT)
		if(!handle_exit(game))
			return;

	update_player_position(game, new_x, new_y);
}
/* 
static void move_player(Game *game, int dx, int dy)
{
	int new_x;
	int new_y;

	new_x = game->player.position_x + dx;
	new_y = game->player.position_y + dy;
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
		// Remove a imagem visual
		if (game->map.instances[new_y][new_x])
		{
			mlx_delete_image(game->mlx, game->map.instances[new_y][new_x]);
			game->map.instances[new_y][new_x] = NULL;
		}
		ft_printf("🍇 Coletando: %i/%i\n", game->player.collectibles, game->map.total_collectibles);
	}
	if (next_tile == EXIT)
	{
		if (game->player.collectibles == game->map.total_collectibles)
		{
			ft_printf("\n🍻 Saída alcançada!\n");
			ft_printf("👯 Total de movimentos:%i\n", game->player.moves + 1);
			ft_printf("🍇 Total da coleta: %i/%i\n", game->player.collectibles, game->map.total_collectibles);
			mlx_close_window(game->mlx);
			return;
		}
		else
		{
			ft_printf("⚠️ Você ainda não coletou todos os itens!\n");
			return;
		}
	}
	draw_tile(game, EMPTY, game->player.position_x, game->player.position_y);
	// Atualiza posição do player
	game->player.position_x = new_x;
	game->player.position_y = new_y;
	// Redesenha a nova posição com o player
	draw_tile(game, PLAYER, new_x, new_y);
	// Atualiza o mapa
	game->map.map[new_y][new_x] = PLAYER;
	game->player.moves++;
	ft_printf("👯 Movimentos: %i\n", game->player.moves);
} */
