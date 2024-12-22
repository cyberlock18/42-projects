/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:15 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/12/18 21:44:09 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

 t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->position = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

 void	add_node_to_stack(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

t_node	*parse_stack(int argc, char **argv)
{
	t_node	*stack;
	t_node	*new_node;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = create_node(atoi(argv[i]));
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		add_node_to_stack(&stack, new_node);
		i++;
	}
	return (stack);
}


void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
int	stack_size(t_node *stack)
{
	int	size;
	
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
