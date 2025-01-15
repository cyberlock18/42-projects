/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:53:28 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 13:58:07 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	cleanup_and_exit(t_node **stack_a, char **args, t_args_info *info)
{
	free_stack(stack_a);
	if (info->is_dynamic)
		free_args(args, info->new_argc);
}

int	process_and_validate_args(int argc, char **argv, char ***args,
		t_args_info *info)
{
	*args = split_arguments(argc, argv, &info->new_argc, &info->is_dynamic);
	if (!(*args) || !handle_spcs_and_empargs(info->new_argc, *args)
		|| !validate_args(info->new_argc, *args))
	{
		if (info->is_dynamic && *args)
			free_args(*args, info->new_argc);
		if (ft_strchr(argv[1], 'a') || !is_valid_number(argv[1]))
			write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
