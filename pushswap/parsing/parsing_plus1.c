/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plus1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:58:46 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/14 14:20:27 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	**split_arguments(int argc, char **argv, int *new_argc, int *is_dynamic)
{
	char	**args;
	char	*cleaned;
	int		count;

	if (argc == 2)
	{
		cleaned = clean_argument(argv[1]);
		if (!cleaned)
			return (NULL);
		args = ft_split(cleaned, ' ');
		free(cleaned);
		if (!args)
			return (NULL);
		*is_dynamic = 1;
		count = 0;
		while (args[count])
			count++;
		*new_argc = count;
		return (args);
	}
	*new_argc = argc - 1;
	*is_dynamic = 0;
	return (argv + 1);
}

t_node	*build_stack(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	int		value;
	int		error;

	stack_a = NULL;
	i = 0;
	while (i < argc)
	{
		value = ft_atoi_safe(argv[i], &error);
		if (error)
		{
			ft_printf("Error\n");
			free_stack(&stack_a);
			exit(1);
		}
		add_node_to_stack(&stack_a, create_node(value));
		i++;
	}
	assign_indices(stack_a);
	return (stack_a);
}

void	parse_and_store(char **argv, t_node **stack)
{
	char	*trim;
	int		i;
	int		value;
	int		error;

	i = 0;
	while (argv[i])
	{
		trim = ft_strtrim(argv[i], " ");
		if (!trim || !ft_strlen(trim) || !validate_input(trim))
			handle_error(stack, trim);
		value = ft_atoi_safe(trim, &error);
		free(trim);
		if (error)
			handle_error(stack, NULL);
		add_node_to_stack(stack, create_node(value));
		i++;
	}
}

int	validate_input(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !ft_strlen(arg))
		return (0);
	while (arg[i] == ' ')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i + 1] == '-' || arg[i + 1] == '+')
			return (0);
		i++;
	}
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	handle_spcs_and_empargs(int argc, char **argv)
{
	char	*trim;
	int		i;

	i = 0;
	while (i < argc)
	{
		trim = ft_strtrim(argv[i], " ");
		if (!trim || ft_strlen(trim) == 0)
		{
			free(trim);
			return (0);
		}
		free(trim);
		i++;
	}
	return (1);
}
