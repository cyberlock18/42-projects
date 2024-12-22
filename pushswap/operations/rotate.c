/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:39:02 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/12/19 08:34:51 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_node **stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}
