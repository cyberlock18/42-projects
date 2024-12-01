/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:29:17 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/26 21:47:44 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define READ_END 0
# define WRITE_END 1

void	first_child(int pipefd[2], char *infile, char *cmd, char *envp[]);
void	second_child(int pipefd[2], char *infile, char *cmd, char *envp[]);
void	handle_cmd(char *cmd, char **envp);
void	freedoublepointer(char **ptr);
int		openfile(char *filename, int flags, int mode);
char	*pathseek(char *cmd, char **envp);
char	*get_path(char **paths, char *cmd);
void	ft_printf(const char *format, ...);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
void	check_exec_status(pid_t pid, int *status, char *command);
void	ft_print_error(char *msg, char *value, int newline, int fd);

#endif