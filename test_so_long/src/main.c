/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:18:49 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/07 23:16:30 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void close_game(void *param)
{
	Game *game = (Game *)param;
	free_game(game);
	exit(EXIT_SUCCESS);
}

int32_t main(int argc, char **argv)
{
	(void)argv;
	if(argc != 2)
	{
		ft_printf("Usage: ./so_long <map_file>\n");
		return (EXIT_FAILURE);
	}

	Game *game = ft_calloc(1, sizeof(Game));
	if(!game)
	{
		ft_printf("Memory allocation failed\n");
		return (EXIT_FAILURE);
	}

	if(!parse_map(game, argv[1]))
	{
		free(game);
		ft_printf("Failed to parse map [main]\n");
		return (EXIT_FAILURE);
	}

	game->tile_size = TILE_SIZE; 
	game->mlx = mlx_init(game->map.width * game->tile_size,
					 game->map.height * game->tile_size,
					 "so_long", false);
	if (!game->mlx)
	{
		ft_printf("Failed to init MLX\n");
		free_game(game);
		return (EXIT_FAILURE);
	}

	load_textures(game);
	render_map(game);

	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop(game->mlx); // mostra janela e mantém aberta

	free_game(game); // caso feche
	return (EXIT_SUCCESS);
}
