/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:28:36 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/28 22:08:24 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_leng(long num)
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
	long	num;

	num = (long)n;
	lng = ft_num_leng(num);
	sol = (char *)malloc((lng + 1) * sizeof(char));
	if (!sol)
		return (NULL);
	sol[lng] = '\0';
	pos = lng - 1;
	if (num < 0)
	{
		sol[0] = '-';
		num *= -1;
	}
	while (num > 9)
	{
		sol[pos] = (num % 10) + '0';
		num /= 10;
		pos--;
	}
	sol[pos] = num + '0';
	return (sol);
}
