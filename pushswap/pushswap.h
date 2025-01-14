/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:56:51 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/14 14:48:37 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}					t_node;
typedef struct s_args_info
{
	int				new_argc;
	int				is_dynamic;
}					t_args_info;

void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

int					validate_args(int argc, char **argv);
int					has_duplicates(char **args, int size);
int					is_valid_number(const char *str);
t_node				*create_node(int value);
void				add_node_to_stack(t_node **stack, t_node *new_node);
void				free_stack(t_node **stack);
void				sort_small_stack(t_node **stack_a, t_node **stack_b);
void				sort_large_stack(t_node **stack_a, t_node **stack_b);
int					ft_atoi_safe(const char *str, int *error);
void				handle_sorting(t_node **stack_a, t_node **stack_b,
						int argc);
int					stack_size(t_node *stack);
int					validate_input(char *arg);
void				parse_and_store(char **argv, t_node **stack);
t_node				*build_stack(int argc, char **argv);
void				assign_index_to_node(t_node *current, t_node *stack);
void				assign_indices(t_node *stack);
int					is_sorted(t_node *stack);
void				free_stack(t_node **stack);
void				free_split(char **args);
char				**split_arguments(int argc, char **argv, int *new_argc,
						int *is_dynamic);
int					handle_spcs_and_empargs(int argc, char **argv);
void				free_args(char **args, int is_dynamic);
void				handle_error(t_node **stack, char *trim);
char				**allocate_and_split(char *arg, int *count);
char				*clean_argument(const char *arg);
void				cleanup_and_exit(t_node **stack_a, char **args,
						t_args_info *info);
int					process_and_validate_args(int argc, char **argv,
						char ***args, t_args_info *info);
int					find_position(t_node *stack, int target_index);
#endif
