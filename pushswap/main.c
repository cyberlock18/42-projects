/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:49:01 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/12/20 12:53:38 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


static void	assign_index_to_node(t_node *current, t_node *stack)
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

static void	assign_indices(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current)
	{
		assign_index_to_node(current, stack);
		current = current->next;
	}
}

static int	is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}


void handle_sorting(t_node **stack_a, t_node **stack_b, int argc)
{
	if (argc <= 6)
		sort_small_stack(stack_a, stack_b);
	else
	{
		sort_large_stack(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (!validate_args(argc, argv))
	{
		ft_printf("error");
		return (1);
	}
	stack_a = parse_stack(argc, argv);
	if (!stack_a)
	{
		ft_printf("error");
			return (1);
	}
	stack_b = NULL;
	assign_indices(stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	handle_sorting(&stack_a, &stack_b, argc);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

