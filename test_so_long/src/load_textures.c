/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:22:52 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/07 23:02:22 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(Game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("assets/img/wall.png");
	game->textures.wall = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/img/floor.png");
	game->textures.floor = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/img/player.png");
	game->textures.player = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/img/collectible.png");
	game->textures.collectible = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/img/exit.png");
	game->textures.exit = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	if (!game->textures.wall || !game->textures.floor || !game->textures.player
		|| !game->textures.collectible || !game->textures.exit)
	{
		ft_printf("Failed to load all textures\n");
	}
}
