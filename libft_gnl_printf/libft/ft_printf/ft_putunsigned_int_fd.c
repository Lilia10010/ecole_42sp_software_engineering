/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:57 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/10 18:31:56 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_int_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n / 10)
		len += ft_putunsigned_int_fd(n / 10, fd);
	len += ft_putchar_fd(n % 10 + '0', fd);
	return (len);
}
