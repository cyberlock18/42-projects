/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:49:01 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/08 12:58:12 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void assign_index_to_node(t_node *current, t_node *stack)
{
    t_node *compare;
    int index;

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

void assign_indices(t_node *stack)
{
    t_node *current;

    current = stack;
    while (current)
    {
        assign_index_to_node(current, stack);
        current = current->next;
    }
}

int is_sorted(t_node *stack)
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
        sort_large_stack(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    char    **args;
    int     new_argc;
    int     is_dynamic;

    if (argc <= 2)
        return (0);
    if (!process_and_validate_args(argc, argv, &args, &new_argc, &is_dynamic))
        return (1);
    stack_a = build_stack(new_argc, args);
    stack_b = NULL;
    if (is_sorted(stack_a))
    {
        cleanup_and_exit(&stack_a, args, new_argc, is_dynamic);
        return (0);
    }
    handle_sorting(&stack_a, &stack_b, new_argc);
    cleanup_and_exit(&stack_a, args, new_argc, is_dynamic);
    free_stack(&stack_b);
    return (0);
}
