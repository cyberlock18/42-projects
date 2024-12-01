/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:45:25 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/26 21:47:37 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_error(char *msg, char *value, int newline, int fd)
{
	if (msg)
		ft_putstr_fd(msg, fd);
	if (value)
		ft_putstr_fd(value, fd);
	if (newline)
		ft_putchar_fd('\n', fd);
}

void	first_child(int pipefd[2], char *infile, char *cmd, char *envp[])
{
	int	infile_fd;

	infile_fd = openfile(infile, O_RDONLY, 0);
	if (infile_fd == -1)
	{
		ft_print_error("Error: Unable to open input file ", infile, 1, 2);
		exit(1);
	}
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
	if (outfile_fd == -1)
	{
		ft_printf("Error: Unable to open or create output file %s\n", outfile);
		exit(1);
	}
	dup2(pipefd[READ_END], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(pipefd[READ_END]);
	close(pipefd[WRITE_END]);
	handle_cmd(cmd, envp);
	close(outfile_fd);
	exit(0);
}
