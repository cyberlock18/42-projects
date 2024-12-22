/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:03:04 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/12/19 08:36:19 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	swap_top_two(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_node **stack_a)
{
	swap_top_two(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	swap_top_two(stack_b);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
	ft_printf("ss\n");
}
