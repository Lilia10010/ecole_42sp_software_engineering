/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:18:49 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 21:39:32 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	start_game(t_Game *game)
{
	load_textures(game);
	render_map(game);
	mlx_key_hook(game->mlx, &ft_key_hook, game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop(game->mlx);
	free_game(game);
}

int32_t	main(int argc, char **argv)
{
	t_Game	*game;

	game = ft_calloc(1, sizeof(t_Game));
	if (argc != 2)
		return (return_error(game, "Usage: ./so_long <map>", EXIT_FAILURE));
	if (!game)
		return (return_error(game, "Failed to allocate memory", EXIT_FAILURE));
	if (!parse_map(game, argv[1]))
		return (return_error(game, "Failed to parse map", EXIT_FAILURE));
	game->tile_size = TILE_SIZE;
	game->mlx = mlx_init(game->map.width * game->tile_size,
			game->map.height * game->tile_size, "so_long", false);
	if (!game->mlx)
		return (return_error(game, "Failed to initialize MLX", EXIT_FAILURE));
	start_game(game);
	return (EXIT_SUCCESS);
}
