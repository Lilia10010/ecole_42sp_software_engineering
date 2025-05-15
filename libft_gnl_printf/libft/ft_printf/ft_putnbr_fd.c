/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:33:53 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/12 20:40:25 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		sign;
	int		len;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (n / 10)
		len += ft_putnbr_fd(n / 10 * sign, fd);
	c = '0' + (n % 10) * sign;
	len += ft_putchar_fd(c, fd);
	return (len);
}
