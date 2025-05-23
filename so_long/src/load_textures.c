/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:22:52 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 21:37:07 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_Game *game)
{
	game->textures.wall = mlx_load_png("assets/img/wall.png");
	game->textures.floor = mlx_load_png("assets/img/floor.png");
	game->textures.player = mlx_load_png("assets/img/player.png");
	game->textures.collectible = mlx_load_png("assets/img/collectible.png");
	game->textures.exit = mlx_load_png("assets/img/exit.png");
	if (!game->textures.wall || !game->textures.floor || !game->textures.player
		|| !game->textures.collectible || !game->textures.exit)
	{
		exit_with_error(game, "Failed to load textures");
	}
}
