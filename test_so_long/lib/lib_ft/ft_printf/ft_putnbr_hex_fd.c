/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:04:20 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:49:44 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_fd_print(unsigned int n, int fd, int is_upper)
{
	int		len;
	char	*base;

	len = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_putnbr_hex_fd_print(n / 16, fd, is_upper);
	len += ft_putchar_fd_print(base[n % 16], fd);
	return (len);
}
