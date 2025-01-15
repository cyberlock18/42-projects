/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:01:09 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/02 18:04:44 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (nbr < 0 && nbr >= (-2147483647 - 1))
		{
			ft_putchar_fd('-', fd);
			nbr = -nbr;
		}
		if (nbr > 9 && nbr <= 2147483648)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putchar_fd(((nbr % 10) + '0'), fd);
		}
		else
			ft_putchar_fd(((nbr % 10) + '0'), fd);
	}
}

int	main(void)
{
	int	num;

	num = open("elquetuquieras.txt", O_WRONLY);
	ft_putnbr_fd(42, num);
	return (0);
}
