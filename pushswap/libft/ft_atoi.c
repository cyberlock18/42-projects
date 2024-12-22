/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:13:34 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/10/01 23:10:16 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_space(int c)
{
	while ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

long	ft_atoi(const char *ps)
{
	long	answ;
	long	sign;
	long	i;

	answ = 0;
	sign = 1;
	i = 0;
	while (ft_space(ps[i]))
		i++;
	if (ps[i] == '+' && ps[i + 1] != '-')
		i++;
	if (ps[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ps[i] >= '0' && ps[i] <= '9')
	{
		answ = answ * 10 + (ps[i] - '0');
		i++;
	}
	return (sign * answ);
}
