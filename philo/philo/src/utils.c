/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:06:42 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/05/04 03:23:12 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

suseconds_t ft_atol(const char *n)
{
    char        sign;
    suseconds_t result;

    sign = 1;
    result = 0;
    while (*n == 32 || (*n >= 9 && *n <= 13))
        ++n;
    if (*n == '+' || *n == '-')
    {
        if (*n == '-')
            sign = -1;
        ++n;
    }
    while (*n >= '0' && *n <= '9')
    {
        result = result * 10 + (*n - '0');
        ++n;
    }
    return (result * sign);
}