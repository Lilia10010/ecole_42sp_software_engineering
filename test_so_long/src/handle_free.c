/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:12:04 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 21:36:25 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < height)
		free(map[i++]);
	free(map);
}

void	free_textures(t_Game *game)
{
	if (game->textures.wall)
		mlx_delete_texture(game->textures.wall);
	if (game->textures.floor)
		mlx_delete_texture(game->textures.floor);
	if (game->textures.player)
		mlx_delete_texture(game->textures.player);
	if (game->textures.collectible)
		mlx_delete_texture(game->textures.collectible);
	if (game->textures.exit)
		mlx_delete_texture(game->textures.exit);
}

void	free_game(t_Game *game)
{
	if (!game)
		return ;
	if (game->map.map)
		free_map(game->map.map, game->map.height);
	free_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}
