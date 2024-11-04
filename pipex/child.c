/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:45:25 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/03 20:44:43 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int pipefd[2], char *infile, char *cmd, char *envp[])
{
	int	infile_fd;

	infile_fd = openfile(infile, O_RDONLY, 0);
	ft_printf("Infile FD: %d\n", infile_fd);
	dup2(infile_fd, STDIN_FILENO);
	dup2(pipefd[WRITE_END], STDOUT_FILENO);
	close(pipefd[READ_END]);
	close(pipefd[WRITE_END]);
	handle_cmd(cmd, envp);
	close(infile_fd);
	exit(0);
}

void	second_child(int pipefd[2], char *cmd, char *outfile, char *envp[])
{
	int	outfile_fd;

	outfile_fd = openfile(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_printf("Outfile FD: %d\n", outfile_fd);
	dup2(pipefd[READ_END], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(pipefd[READ_END]);
	close(pipefd[WRITE_END]);
	handle_cmd(cmd, envp);
	close(outfile_fd);
	exit(0);
}
