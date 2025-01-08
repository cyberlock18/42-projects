/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plus1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:58:46 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/08 09:39:33 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char **split_arguments(int argc, char **argv, int *new_argc, int *is_dynamic)
{
    char    **args;
    char    *cleaned;
    int     count;

    if (argc == 2)
    {
        cleaned = clean_argument(argv[1]);
        if (!cleaned)
            return (NULL);
        args = ft_split(cleaned, ' ');
        free(cleaned);
        if (!args)
            return (NULL);
        *is_dynamic = 1;
        count = 0;
        while (args[count])
            count++;
        *new_argc = count;
        return (args);
    }
    *new_argc = argc;
    *is_dynamic = 0;    
    return (argv);
}

t_node *build_stack(int argc, char **argv)
{
    t_node *stack_a;

    (void)argc; // Evitar advertencia de parámetro no usado
    stack_a = NULL;
    parse_and_store(argv, &stack_a);
    if (!stack_a)
    {
        ft_printf("Error\n");
        exit(1);
    }
    assign_indices(stack_a);
    return (stack_a);
}

void parse_and_store(char **argv, t_node **stack)
{
    char    *trim;
    int     i;
    int     value;
    int     error;

    i = 1;
    while (argv[i])
    {
        trim = ft_strtrim(argv[i], " ");
        if (!trim || !ft_strlen(trim) || !validate_input(trim)) // Valida entrada
            handle_error(stack, trim);
        value = ft_atoi_safe(trim, &error);
        free(trim);
        if (error)
            handle_error(stack, NULL);
        add_node_to_stack(stack, create_node(value));
        i++;
    }
}

int validate_input(char *arg)
{
    int i;

    i = 0;
    if (!arg || !ft_strlen(arg)) // Detecta cadena vacía
        return (0);
    while (arg[i] == ' ')
        i++;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    if (!arg[i]) // Si solo hay un signo sin número, retorna error
        return (0);
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int handle_spcs_and_emPargs(int argc, char **argv)
{
    char    *trim;
    int     i;

    i = 1;
    while (i < argc)
    {
        trim = ft_strtrim(argv[i], " ");
        if (!trim || ft_strlen(trim) == 0) // Detecta cadenas vacías o solo con espacios
        {
            free(trim);
            return (0); // Error: argumento vacío
        }
        free(trim);
        i++;
    }
    return (1); // Todo correcto
}
