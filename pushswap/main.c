/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:49:01 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 14:02:39 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_index_to_node(t_node *current, t_node *stack)
{
	t_node	*compare;
	int		index;

	index = 0;
	compare = stack;
	while (compare)
	{
		if (current->value > compare->value)
			index++;
		compare = compare->next;
	}
	current->index = index;
}

void	assign_indices(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current)
	{
		assign_index_to_node(current, stack);
		current = current->next;
	}
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	handle_sorting(t_node **stack_a, t_node **stack_b, int argc)
{
	if (argc <= 6)
		sort_small_stack(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	char		**args;
	t_args_info	info;

	if (argc < 2)
		return (0);
	if (!process_and_validate_args(argc, argv, &args, &info))
		return (1);
	if (!args || info.new_argc == 1)
	{
		if (info.is_dynamic)
			free_args(args, info.new_argc);
		return (0);
	}
	stack_a = build_stack(info.new_argc, args);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (cleanup_and_exit(&stack_a, args, &info), 0);
	handle_sorting(&stack_a, &stack_b, info.new_argc);
	cleanup_and_exit(&stack_a, args, &info);
	free_stack(&stack_b);
	return (0);
}
