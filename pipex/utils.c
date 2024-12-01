/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:18:43 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/30 18:33:23 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_print_error("Command not found", cmd, 1, 2);
		exit(127);
	}
	path = pathseek(args[0], envp);
	if (!path)
	{
		ft_print_error("Command not found", args[0], 1, 2);
		freedoublepointer(args);
		exit(127);
	}
	if (execve(path, args, envp) == -1)
	{
		ft_printf("Failed to execute command: %s\n", args[0]);
		free(path);
		freedoublepointer(args);
		exit(126);
	}
	free(path);
	freedoublepointer(args);
}

void	freedoublepointer(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	openfile(char *filename, int flags, int mode)
{
	int	fd;

	fd = open(filename, flags, mode);
	if (fd < 0)
	{
		ft_printf("Error opening file: %s\n", filename);
		exit(1);
	}
	return (fd);
}

char	*get_path(char **paths, char *cmd)
{
	char	*path;
	char	*full_path;

	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		paths++;
	}
	return (NULL);
}

char	*pathseek(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;

	i = 0;
	while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	path = get_path(paths, cmd);
	freedoublepointer(paths);
	return (path);
}
