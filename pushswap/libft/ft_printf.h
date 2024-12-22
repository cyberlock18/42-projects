/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:22:27 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/02 19:04:43 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_strchr1(const char *s, int c);
int		ft_putstr1(va_list args);
int		ft_putchr1(va_list args);
size_t	ft_strlen1(const char *c);
int		ft_putnbr1(va_list args, char type);
int		put_hex(unsigned long long i, char format);
int		put_pntr(void *ptr);
int		ft_printf(const char *format, ...);
int		put_digit(unsigned long nbr);

#endif