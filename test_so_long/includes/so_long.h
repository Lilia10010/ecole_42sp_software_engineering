#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
# include "../lib/lib_ft/lib_ft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"

#define TILE_SIZE 64

typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
} TileType;

typedef struct s_player
{
	int		position_x;
	int		position_y;
	size_t	moves;
	size_t	collectibles;
}	Player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			exit_x;
	int			exit_y;
	size_t		total_collectibles;
	mlx_image_t	*instances[100][100];
}	Map;

typedef struct s_textures
{
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
}	Textures;

typedef struct s_game 
{
	mlx_t			*mlx;
	mlx_image_t		*player_img;
	Player			player;
	Map				map;
	bool			exit_unlocked;
	Textures		textures;
	int				tile_size;
	double			last_move_time;
	double			move_delay;
} Game;

void close_game(void *param);
void free_game(Game *game);
void	free_map(char **map, int height);
void	free_textures(Game *game);

int return_error(Game *game, const char *message, int code);
void	exit_with_error(Game *game, const char *msg);
void	check_exit(Game *game);

bool parse_map(Game *game, const char *filename);

void	load_textures(Game *game);
void render_map(Game *game);
void draw_tile(Game *game, char tile, int x, int y);
void ft_key_hook(mlx_key_data_t keydata, void *param);
void	move_player(Game *game, int horizontal_move, int vertical_move);
bool check_map_reachability(Game *game);
int check_map_shape_and_walls(Game *game);
bool parse_map(Game *game, const char *filename);
int check_map_validity(Game *game);

#endif