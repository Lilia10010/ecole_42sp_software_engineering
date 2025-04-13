/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:12:04 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/13 12:12:48 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(Game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		close_game(game);
	}
}

void	close_game(void *param)
{
	Game	*game;

	game = (Game *)param;
	free_game(game);
	exit(EXIT_SUCCESS);
}

int	return_error(Game *game, const char *message, int code)
{
	ft_printf("\033[31m======= %s =======\033[0m\n", message);
	if (game)
		free_game(game);
	else
		ft_printf("Game is NULL\n");
	return (code);
}

void	exit_with_error(Game *game, const char *msg)
{
	ft_printf("\033[31m======= %s =======\033[0m\n", msg);
	free_game(game);
	exit(EXIT_FAILURE);
}
