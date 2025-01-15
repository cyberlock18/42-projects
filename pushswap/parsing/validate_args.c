/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:11:28 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 14:00:44 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static const char	*parse_sign(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int	ft_atoi_safe(const char *str, int *error)
{
	long	result;
	int		sign;

	*error = 0;
	result = 0;
	str = parse_sign(str, &sign);
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > MAX_INT) || (sign == -1
				&& (-result) < MIN_INT))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

int	has_duplicates(char **args, int size)
{
	int	i;
	int	j;
	int	error;
	int	value_i;
	int	value_j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		value_i = ft_atoi_safe(args[i], &error);
		if (error)
			return (1);
		while (j < size)
		{
			value_j = ft_atoi_safe(args[j], &error);
			if (!error && value_i == value_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int	i;
	int	error;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		ft_atoi_safe(argv[i], &error);
		if (error)
			return (0);
		i++;
	}
	if (has_duplicates(argv, argc))
		return (0);
	return (1);
}
