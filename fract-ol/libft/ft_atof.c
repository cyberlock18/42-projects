/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:38:49 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 21:38:53 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_fraction(const char *str)
{
	double	fraction;
	int		divisor;

	fraction = 0.0;
	divisor = 1;
	while (*str >= '0' && *str <= '9')
	{
		fraction = fraction * 10 + (*str - '0');
		divisor *= 10;
		str++;
	}
	return (fraction / divisor);
}

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = parse_sign(&str);
	result = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		fraction = parse_fraction(++str);
	else
		fraction = 0.0;
	return (sign * (result + fraction));
}
