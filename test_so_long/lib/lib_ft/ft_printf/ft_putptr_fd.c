/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:43:56 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:50:07 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex_print(uintptr_t n, int fd)
{
	int		len;
	char	*hex_digits;

	len = 0;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_putnbr_hex_print(n / 16, fd);
	len += ft_putchar_fd_print(hex_digits[n % 16], fd);
	return (len);
}

int	ft_putptr_fd_print(void *ptr, int fd)
{
	int			len;
	uintptr_t	address;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = 0;
	address = (uintptr_t)ptr;
	len += ft_putstr_fd_print("0x", fd);
	len += ft_putnbr_hex_print(address, fd);
	return (len);
}
