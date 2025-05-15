/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:28:47 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/01 22:30:15 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	c;
	long	num;

	num = n;
	sign = 1;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (num / 10)
		ft_putnbr_fd(num / 10 * sign, fd);
	c = '0' + (num % 10) * sign;
	ft_putchar_fd(c, fd);
}
