/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:57 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:51:46 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_int_fd_print(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n / 10)
		len += ft_putunsigned_int_fd_print(n / 10, fd);
	len += ft_putchar_fd_print(n % 10 + '0', fd);
	return (len);
}
