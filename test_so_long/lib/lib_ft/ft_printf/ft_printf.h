/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:40:39 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/04/07 17:48:41 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd_print(char c, int fd);
int	ft_putnbr_fd_print(int n, int fd);
int	ft_putptr_fd_print(void *ptr, int fd);
int	ft_putstr_fd_print(char *str, int fd);
int	ft_putunsigned_int_fd_print(unsigned int n, int fd);
int	ft_putnbr_hex_fd_print(unsigned int n, int fd, int is_upper);

#endif
