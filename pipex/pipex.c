/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:29:47 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/18 23:19:42 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_args(int argc)
{
	if (argc != 5)
	{
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(1);
	}
}

void	create_pipes(int fd[2])
{
	if (pipe(fd) == -1)
	{
		ft_printf("Pipe error\n");
		exit(1);
	}
}

void	handle_fork_error(pid_t pid, char *message)
{
	if (pid < 0)
	{
		ft_printf("%s\n", message);
		exit(1);
	}
}

void	close_pipes(int fd[2])
{
	close(fd[READ_END]);
	close(fd[WRITE_END]);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	validate_args(argc);
	create_pipes(pipefd);
	pid1 = fork();
	handle_fork_error(pid1, "Fork error for first child");
	if (pid1 == 0)
		first_child(pipefd, argv[1], argv[2], envp);
	pid2 = fork();
	handle_fork_error(pid2, "Fork error for second child");
	if (pid2 == 0)
		second_child(pipefd, argv[3], argv[4], envp);
	close_pipes(pipefd);
	check_exec_status(pid2, &status, argv[3]);
	return (0);
}
