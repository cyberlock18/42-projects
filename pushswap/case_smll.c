/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_smll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:40:13 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/07 19:51:20 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

static int	find_min_index(t_node *stack)
{
	int	min_index;

	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

static void	push_min_to_b(t_node **stack_a, t_node **stack_b)
{
	int	min_index;
	int	position;

	min_index = find_min_index(*stack_a);
	position = find_position(*stack_a, min_index);
	while ((*stack_a)->index != min_index)
	{
		if (position <= stack_size(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

static void	push_and_sort(t_node **stack_a, t_node **stack_b, int size)
{
	while (size-- > 3)
	{
		push_min_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}

void	sort_small_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		push_and_sort(stack_a, stack_b, size);
}
