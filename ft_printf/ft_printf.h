/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:40:39 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/12 22:47:35 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putptr_fd(void *ptr, int fd);
int	ft_putstr_fd(char *str, int fd);
int	ft_putunsigned_int_fd(unsigned int n, int fd);
int	ft_putnbr_hex_fd(unsigned int n, int fd, int is_upper);

#endif
