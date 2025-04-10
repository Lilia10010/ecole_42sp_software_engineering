/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:23:58 by microbiana        #+#    #+#             */
/*   Updated: 2025/04/07 21:48:34 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_game(Game *game)
{
	if (!game)
		return;
	int i;

	i = 0;
	if (game->map.map)
	{
		while (game->map.map[i])
			free(game->map.map[i++]);
		free(game->map.map);
	}

	free(game);
}