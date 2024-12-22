/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:38:43 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/12/18 14:38:20 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	reverse_rotate_stack(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	reverse_rotate_stack(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	ft_printf("rrr\n");
}
