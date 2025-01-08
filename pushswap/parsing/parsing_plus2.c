/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:53:28 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/08 12:57:25 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void cleanup_and_exit(t_node **stack_a, char **args, int new_argc, int is_dynamic)
{
    free_stack(stack_a);
    if (is_dynamic)
        free_args(args, new_argc);
}
int process_and_validate_args(int argc, char **argv, char ***args, int *new_argc, int *is_dynamic)
{
    *args = split_arguments(argc, argv, new_argc, is_dynamic);
    if (!(*args) || !handle_spcs_and_emPargs(*new_argc, *args) || !validate_args(*new_argc, *args))
    {
        if (*is_dynamic)
            free_args(*args, *new_argc);
        ft_printf("Error\n");
        return (0);
    }
    return (1);
}
