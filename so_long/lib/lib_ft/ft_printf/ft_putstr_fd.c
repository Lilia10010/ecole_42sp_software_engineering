/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:33:00 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:50:25 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_print(char *str, int fd)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		len += ft_putchar_fd_print(*str, fd);
		++str;
	}
	return (len);
}
