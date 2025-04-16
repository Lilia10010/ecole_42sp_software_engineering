/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:33:53 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:49:22 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_print(int n, int fd)
{
	char	c;
	int		sign;
	int		len;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		len += ft_putchar_fd_print('-', fd);
		sign = -1;
	}
	if (n / 10)
		len += ft_putnbr_fd_print(n / 10 * sign, fd);
	c = '0' + (n % 10) * sign;
	len += ft_putchar_fd_print(c, fd);
	return (len);
}
