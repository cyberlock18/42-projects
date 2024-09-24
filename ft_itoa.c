/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:28:36 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/23 20:07:36 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_leng(long num)
{
	int	i;

	i = 1;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*sol;
	int		pos;
	int		lng;

	lng = ft_num_leng(n);
	sol = (char *)malloc((lng + 1) * sizeof(char));
	if (!sol)
		return (NULL);
	pos = lng - 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return ("-2147483648");
		n *= -1;
		sol[0] = '-';
	}
	while (n > 9)
	{
		sol[pos] = (n % 10) + '0';
		n = n / 10;
		pos--;
	}
	if (n <= 9)
		sol[pos] = n + '0';
	return (sol);
}
