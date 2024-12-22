/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:11:28 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/12/21 19:50:16 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

 int	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
 int	ft_atoi_safe(const char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error = 0;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > MAX_INT) || (sign == -1 && -result < MIN_INT))
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
			return (1); // Duplicado debido a un número inválido
		while (j < size)
		{
			value_j = ft_atoi_safe(args[j], &error);
			if (!error && value_i == value_j)
				return (1); // Duplicado encontrado
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
	i = 1;
	while (i < argc)
	{
		ft_atoi_safe(argv[i], &error);
		if (error)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	if (has_duplicates(argv + 1, argc - 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

