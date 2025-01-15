/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:22:23 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/03 17:20:29 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_digit(unsigned long nbr)
{
	char	digit;
	int		count;

	count = 0;
	if (nbr >= 10)
		count += put_digit(nbr / 10);
	digit = (nbr % 10) + '0';
	write(1, &digit, 1);
	return (count + 1);
}

static void	parse_format(const char *format, int *i, va_list args, int *count)
{
	if (format[*i + 1] == 'c')
		*count += ft_putchr1(args);
	else if (format[*i + 1] == 's')
		*count += ft_putstr1(args);
	else if (format[*i + 1] == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		*count += ft_putnbr1(args, format[*i + 1]);
	else if (format[*i + 1] == 'u')
		*count += ft_putnbr1(args, 'u');
	else if (format[*i + 1] == 'x' || format[*i + 1] == 'X')
		*count += put_hex(va_arg(args, unsigned int), format[*i + 1]);
	else if (format[*i + 1] == 'p')
		*count += put_pntr(va_arg(args, void *));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			parse_format(format, &i, args, &count);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	void *ptr1 = malloc(42);
// 	void *ptr2 = NULL;
// 	void *ptr3 = (void *)LONG_MIN;
// 	void *ptr4 = (void *)ULONG_MAX;
// 	void *ptr5 = (void *)LONG_MAX;

// 	printf("Original printf:\n");
// 	printf(" %p\n", ptr1);
// 	printf(" %p\n", ptr2);
// 	printf(" %p\n", ptr3);
// 	printf(" %p\n", ptr4);
// 	printf(" %p\n", ptr5);

// 	printf("\nft_printf:\n");
// 	ft_printf(" %p\n", ptr1);
// 	ft_printf(" %p\n", ptr2);
// 	ft_printf(" %p\n", ptr3);
// 	ft_printf(" %p\n", ptr4);
// 	ft_printf(" %p\n", ptr5);

// 	free(ptr1);
// 	return (0);
// }