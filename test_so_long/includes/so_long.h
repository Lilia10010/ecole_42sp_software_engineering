/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:25:49 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/13 21:44:35 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../lib/lib_ft/lib_ft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 64

typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}	t_TileType;

typedef struct s_player
{
	int		position_x;
	int		position_y;
	size_t	moves;
	size_t	collectibles;
}	t_Player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			exit_x;
	int			exit_y;
	size_t		total_collectibles;
	mlx_image_t	*instances[100][100];
}	t_Map;

typedef struct s_textures
{
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
}	t_Textures;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*player_img;
	t_Player		player;
	t_Map			map;
	bool			exit_unlocked;
	t_Textures		textures;
	int				tile_size;
}	t_Game;

void	close_game(void *param);
void	free_game(t_Game *game);
void	free_map(char **map, int height);
void	free_textures(t_Game *game);
int		return_error(t_Game *game, const char *message, int code);
void	exit_with_error(t_Game *game, const char *msg);
void	check_exit(t_Game *game);
bool	parse_map(t_Game *game, const char *filename);
void	load_textures(t_Game *game);
void	render_map(t_Game *game);
void	draw_tile(t_Game *game, char tile, int x, int y);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	move_player(t_Game *game, int horizontal_move, int vertical_move);
bool	check_map_reachability(t_Game *game);
int		check_map_shape_and_walls(t_Game *game);
bool	parse_map(t_Game *game, const char *filename);
int		check_map_validity(t_Game *game);

#endif