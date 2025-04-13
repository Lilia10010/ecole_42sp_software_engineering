/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:21:51 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/11 14:26:08 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_tile(Game *game, char tile, int x, int y)
{
	mlx_image_t *img = NULL;

	if (tile == '1') // WALL
	{
		img = mlx_texture_to_image(game->mlx, game->textures.floor);
		mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
		game->map.instances[y][x] = img;

		img = mlx_texture_to_image(game->mlx, game->textures.wall);
	}
	else if (tile == '0') // FLOOR
	{
		img = mlx_texture_to_image(game->mlx, game->textures.floor);
	}
	else if (tile == 'P') // PLAYER
	{
		img = mlx_texture_to_image(game->mlx, game->textures.floor);
		mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);

		img = mlx_texture_to_image(game->mlx, game->textures.player);
	}
	else if (tile == 'C') // COLLECTIBLE
	{
		img = mlx_texture_to_image(game->mlx, game->textures.floor);
		mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);

		img = mlx_texture_to_image(game->mlx, game->textures.collectible);
	}
	else if (tile == 'E') // EXIT
	{
		img = mlx_texture_to_image(game->mlx, game->textures.floor);
		mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);

		img = mlx_texture_to_image(game->mlx, game->textures.exit);
	}

	// Instancia e guarda a imagem final no mapa
	if (img)
	{
		mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
		game->map.instances[y][x] = img;
	}
}


void	render_map(Game *game)
{
	if (!game || !game->map.map)
	{
		ft_printf("Error: Map is not loaded.\n");
		return;
	}
	
	int	y;
	int	x;
	char	tile;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			tile = game->map.map[y][x];
			draw_tile(game, tile, x, y);
			++x;
		}
		++y;
	}
}
