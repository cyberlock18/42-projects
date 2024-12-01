/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:32:53 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/19 20:06:50 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_exec_status(pid_t pid, int *status, char *command)
{
	int	exit_code;
	int	signal_code;

	if (pid > 0)
	{
		waitpid(pid, status, 0);
		if (WIFEXITED(*status))
		{
			exit_code = WEXITSTATUS(*status);
			if (exit_code == 127)
			{
				ft_printf("Command not found: %s\n", command);
			}
			exit(exit_code);
		}
		else if (WIFSIGNALED(*status))
		{
			signal_code = WTERMSIG(*status);
			ft_printf("Command '%s' was terminated by signal %d\n", command,
				signal_code);
			exit(128 + signal_code);
		}
	}
}

void	exit_error(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}
