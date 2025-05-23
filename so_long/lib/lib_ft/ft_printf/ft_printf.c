/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:05:05 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:53:47 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_fd_print((char)va_arg(args, int), 1));
	if (specifier == 's')
		return (ft_putstr_fd_print(va_arg(args, char *), 1));
	if (specifier == 'p')
		return (ft_putptr_fd_print(va_arg(args, void *), 1));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_fd_print(va_arg(args, int), 1));
	if (specifier == 'u')
		return (ft_putunsigned_int_fd_print(va_arg(args, unsigned int), 1));
	if (specifier == 'x' || specifier == 'X')
		return (
			ft_putnbr_hex_fd_print(
				va_arg(args, unsigned int), 1, specifier == 'X'
			)
		);
	if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start (args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += handle_format_specifier(*format, args);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}
