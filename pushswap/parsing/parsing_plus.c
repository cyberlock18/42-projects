/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:52:56 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/14 13:28:45 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
	args = NULL;
}

void	free_args(char **args, int new_argc)
{
	int	i;

	i = 0;
	while (i < new_argc)
	{
		if (args[i] != NULL)
			free(args[i]);
		i++;
	}
	free(args);
}

void	handle_error(t_node **stack, char *trim)
{
	if (trim)
	{
		free(trim);
		trim = NULL;
	}
	if (stack && *stack)
		free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}

char	**allocate_and_split(char *arg, int *count)
{
	char	*cleaned;
	char	**args;

	cleaned = clean_argument(arg);
	if (!cleaned || ft_strlen(cleaned) == 0)
	{
		free(cleaned);
		return (NULL);
	}
	args = ft_split(cleaned, ' ');
	free(cleaned);
	if (!args)
		return (NULL);
	*count = 0;
	while (args[*count])
		(*count)++;
	return (args);
}

char	*clean_argument(const char *arg)
{
	char	*cleaned;
	int		i;
	int		j;

	cleaned = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 1));
	if (!cleaned)
		return (NULL);
	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] != '"' && arg[i] != '\'')
			cleaned[j++] = arg[i];
		i++;
	}
	cleaned[j] = '\0';
	return (cleaned);
}
