/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:18:20 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/18 21:28:59 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

const char	*get_state_message(t_State state)
{
	static const char	*msg[] = {
	[THINKING] = "is thinking",
	[EATING] = "is eating",
	[SLEEPING] = "is sleeping",
	[LEFT_FORK] = "has taken a fork",
	[RIGTH_FORK] = "has taken a fork",
	[DEAD] = "died"
	};

	if (state < 0 || state > DEAD)
		return ("unknown state");
	return (msg[state]);
}
