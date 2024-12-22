/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:23:36 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/02 19:05:46 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr1(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putstr1(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	write(1, str, ft_strlen1(str));
	return (ft_strlen1(str));
}

int	ft_putchr1(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr1(va_list args, char type)
{
	long	nbr;
	int		count;

	count = 0;
	if (type == 'd' || type == 'i')
	{
		nbr = va_arg(args, int);
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			count++;
		}
		count += put_digit(nbr);
	}
	else if (type == 'u')
	{
		nbr = va_arg(args, unsigned int);
		count += put_digit(nbr);
	}
	return (count);
}

size_t	ft_strlen1(const char *c)
{
	size_t	cont;

	cont = 0;
	while (c[cont])
		cont++;
	return (cont);
}
