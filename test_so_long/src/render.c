/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:21:51 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/09 11:28:28 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_tile(Game *game, mlx_image_t *img, int x, int y)
{
	if (!img)
		return;

	mlx_image_to_window(
		game->mlx,
		img,
		x * TILE_SIZE,
		y * TILE_SIZE
	);
}


void	draw_tile(Game *game, char tile, int x, int y)
{
	if (tile == '1')
	{
		put_tile(game, game->textures.floor, x, y);
		put_tile(game, game->textures.wall, x, y);
	}
	else if (tile == '0')
		put_tile(game, game->textures.floor, x, y);
	else if (tile == 'P')
	{
		put_tile(game, game->textures.floor, x, y);
		put_tile(game, game->textures.player, x, y);
	}
	else if (tile == 'C')
	{
		put_tile(game, game->textures.floor, x, y);
		put_tile(game, game->textures.collectible, x, y);
	}
	else if (tile == 'E')
	{
		put_tile(game, game->textures.floor, x, y);
		put_tile(game, game->textures.exit, x, y);
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
			x++;
		}
		y++;
	}
}