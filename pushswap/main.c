/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:49:01 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/08 09:39:46 by ruortiz-         ###   ########.fr       */
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
    int     is_dynamic; // Variable para saber si hay que liberar args

    if (argc <=2)
        return (0);
    args = split_arguments(argc, argv, &new_argc, &is_dynamic);
    if (!args || !handle_spcs_and_emPargs(new_argc, args))
    {
        if (is_dynamic)
            free_args(args, new_argc);
        return (ft_printf("Error\n"), 1);
    }
    stack_a = build_stack(new_argc, args);
    stack_b = NULL;
    if (is_sorted(stack_a))
        return (free_stack(&stack_a),0);
    handle_sorting(&stack_a, &stack_b, new_argc);
    free_stack(&stack_a);
    free_stack(&stack_b);
    if (is_dynamic)
        free_args(args, new_argc); // Liberar solo si fue asignado dinámicamente
    return (0);
}
