/_ ************************************\*\************************************* _/
/\* _/
/_ ::: :::::::: _/
/_ parse_map_old.c :+: :+: :+: _/
/_ +:+ +:+ +:+ _/
/_ By: microbiana <microbiana@student.42.fr> +#+ +:+ +#+ _/
/_ +#+#+#+#+#+ +#+ _/
/_ Created: 2025/04/05 13:02:01 by microbiana #+# #+# _/
/_ Updated: 2025/04/10 22:59:17 by microbiana ### ########.fr _/
/_ _/
/_ ************************************\*\************************************* \*/

#include "../includes/so_long.h"

static int count_map_lines(const char *filename)
{
int fd = open(filename, O_RDONLY);
char *line;
int count = 0;

    if (fd < 0)
    	return (-1);

    while ((line = get_next_line(fd)) != NULL)
    {
    	free(line);
    	count++;
    }
    close(fd);
    return (count);

}

static char **read_map_lines(const char *filename, int *height)
{
int fd;
char \*line;
char **map;
int i = 0;

    *height = count_map_lines(filename);
    if (*height <= 0)
    	return (NULL);

    map = malloc(sizeof(char *) * (*height + 1));
    if (!map)
    	return (NULL);

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    	return (NULL);

    while ((line = get_next_line(fd)) != NULL)
    {
    	map[i++] = ft_strtrim(line, "\n");
    	free(line);
    }
    map[i] = NULL;
    close(fd);
    return (map);

}

static int check_map_validity(Game \*game)
{
int has_player = 0;
int has_exit = 0;
int i, j;

    game->map.total_collectibles = 0;
    for (i = 0; i < game->map.height; i++)
    {
    	for (j = 0; j < game->map.width; j++)
    	{
    		char tile = game->map.map[i][j];
    		if (tile == 'P')
    		{
    			game->player.position_x = j;
    			game->player.position_y = i;
    			has_player++;
    		}
    		else if (tile == 'E')
    		{
    			game->map.exit_x = j;
    			game->map.exit_y = i;
    			has_exit++;
    		}
    		else if (tile == 'C')
    			game->map.total_collectibles++;
    		else if (tile != '1' && tile != '0')
    			return (0);
    	}
    }
    return (has_player == 1 && has_exit == 1 && game->map.total_collectibles > 0);

}

static int check_map_shape_and_walls(Game \*game)
{
int width = ft_strlen(game->map.map[0]);
int i;

    game->map.width = width;

    for (i = 0; i < game->map.height; i++)
    {
    	if ((int)ft_strlen(game->map.map[i]) != width)
    		return (0); // linhas com tamanhos diferentes

    	// checar paredes horizontais
    	if (i == 0 || i == game->map.height - 1)
    	{
    		for (int j = 0; j < width; j++)
    			if (game->map.map[i][j] != '1')
    				return (0);
    	}
    	// checar paredes verticais
    	else
    	{
    		if (game->map.map[i][0] != '1' || game->map.map[i][width - 1] != '1')
    			return (0);
    	}
    }
    return (1);

}

//start - mover para chek_map_reachability.c

static char **copy_map(char **original, int height)
{
char \*_copy = malloc(sizeof(char _) \* (height + 1));
if (!copy)
return NULL;
for (int i = 0; i < height; i++)
copy[i] = ft_strdup(original[i]);
copy[height] = NULL;
return copy;
}

static void flood_fill(char \*\*map, int x, int y)
{
if (y < 0 || x < 0 || !map[y] || !map[y][x]) // checa limites
return;
if (map[y][x] == '1' || map[y][x] == 'F')
return;
map[y][x] = 'F'; // Marca como visitado
flood_fill(map, x + 1, y);
flood_fill(map, x - 1, y);
flood_fill(map, x, y + 1);
flood_fill(map, x, y - 1);
}

static bool has_unreachable_elements(char \*\*map, int height, char target)
{
for (int i = 0; i < height; i++)
{
for (int j = 0; map[i][j]; j++)
{
if (map[i][j] == target)
return true;
}
}
return false;
}

static void free_map(char \*\*map, int height)
{
for (int i = 0; i < height; i++)
free(map[i]);
free(map);
}

static bool check_map_reachability(Game \*game)
{
char \*\*map_copy = copy_map(game->map.map, game->map.height);
if (!map_copy)
return false;

    flood_fill(map_copy, game->player.position_x, game->player.position_y);

    if (has_unreachable_elements(map_copy, game->map.height, 'E'))
    {
    	ft_printf("Error: Unreachable exit\n");
    	free_map(map_copy, game->map.height);
    	return false;
    }
    if (has_unreachable_elements(map_copy, game->map.height, 'C'))
    {
    	ft_printf("Error: Unreachable collectible\n");
    	free_map(map_copy, game->map.height);
    	return false;
    }

    free_map(map_copy, game->map.height);
    return true;

}

//end

bool parse_map(Game *game, const char *filename)
{
int height;

    game->map.map = read_map_lines(filename, &height);
    if (!game->map.map)
    	return (false);

    game->map.height = height;

    if (!check_map_shape_and_walls(game) || !check_map_validity(game) || !check_map_reachability(game))
    {
    	ft_printf("Invalid map\n");
    	return (false);
    }
    	ft_printf("Player pos: x=%d y=%d\n", game->player.position_x, game->player.position_y);


    return (true);

}
