/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:58:21 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/02 20:27:28 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned long long i, char format)
{
	char	*hex_digits;
	int		count;

	hex_digits = NULL;
	count = 0;
	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (i >= 16)
		count += put_hex(i / 16, format);
	write(1, &hex_digits[i % 16], 1);
	count++;
	return (count);
}

int	put_pntr(void *ptr)
{
	unsigned long	ptr_value;
	int				count;

	ptr_value = (unsigned long)ptr;
	count = 0;
	if (ptr_value == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += put_hex(ptr_value, 'x');
	return (count);
}
