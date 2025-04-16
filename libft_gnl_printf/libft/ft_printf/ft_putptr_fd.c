/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:43:56 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/12 22:54:58 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex(uintptr_t n, int fd)
{
	int		len;
	char	*hex_digits;

	len = 0;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_putnbr_hex(n / 16, fd);
	len += ft_putchar_fd(hex_digits[n % 16], fd);
	return (len);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	int			len;
	uintptr_t	address;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = 0;
	address = (uintptr_t)ptr;
	len += ft_putstr_fd("0x", fd);
	len += ft_putnbr_hex(address, fd);
	return (len);
}
