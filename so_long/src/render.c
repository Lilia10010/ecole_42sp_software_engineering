/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:21:51 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 21:43:56 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_tile(t_Game *game, char tile, int x, int y)
{
	mlx_image_t	*floor_img;
	mlx_image_t	*tile_img;

	tile_img = NULL;
	floor_img = mlx_texture_to_image(game->mlx, game->textures.floor);
	if (floor_img)
		mlx_image_to_window(game->mlx, floor_img, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		tile_img = mlx_texture_to_image(game->mlx, game->textures.wall);
	else if (tile == 'P')
		tile_img = mlx_texture_to_image(game->mlx, game->textures.player);
	else if (tile == 'C')
		tile_img = mlx_texture_to_image(game->mlx, game->textures.collectible);
	else if (tile == 'E')
		tile_img = mlx_texture_to_image(game->mlx, game->textures.exit);
	if (tile_img)
	{
		mlx_image_to_window(game->mlx, tile_img, x * TILE_SIZE, y * TILE_SIZE);
		game->map.instances[y][x] = tile_img;
	}
	else
		game->map.instances[y][x] = floor_img;
}

void	render_map(t_Game *game)
{
	int		y;
	int		x;
	char	tile;

	if (!game || !game->map.map)
	{
		ft_printf("Error: Map is not loaded.\n");
		return ;
	}
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
