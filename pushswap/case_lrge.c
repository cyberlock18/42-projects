/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_lrge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:59:24 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/09 12:45:42 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_sqrt(int nbr)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1;
	while (i * i <= nbr)
		i++;
	return (i - 1);
}

static void	push_to_b(t_node **stack_a, t_node **stack_b, int *size_a,
		int *size_b)
{
	int	range;

	range = get_sqrt(*size_a) * 133 / 100;
	while (*size_a > 0)
	{
		if ((*stack_a)->index <= *size_b)
		{
			pb(stack_a, stack_b);
			(*size_a)--;
			(*size_b)++;
		}
		else if ((*stack_a)->index <= *size_b + range)
		{
			pb(stack_a, stack_b);
			(*size_a)--;
			(*size_b)++;
			if (!((*stack_a)->index <= *size_b + range))
				rr(stack_a, stack_b);
			else
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

static void	push_to_a(t_node **stack_a, t_node **stack_b, int *size_a,
		int *size_b)
{
	while (*size_b > 0)
	{
		while ((*stack_b)->index != *size_b - 1)
		{
			if (find_position(*stack_b, *size_b - 1) <= *size_b / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		(*size_a)++;
		(*size_b)--;
	}
}

void	sort_large_stack(t_node **stack_a, t_node **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*stack_a);
	size_b = 0;
	if (size_a > 5)
	{
		push_to_b(stack_a, stack_b, &size_a, &size_b);
		push_to_a(stack_a, stack_b, &size_a, &size_b);
	}
	else
		sort_small_stack(stack_a, stack_b);
}

int	find_position(t_node *stack, int target_index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}
