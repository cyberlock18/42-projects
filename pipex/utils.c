/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:18:43 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/03 20:40:54 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		exit(1);
	path = pathseek(args[0], envp);
	if (!path)
	{
		freedoublepointer(args);
		ft_printf("Command not found: %s\n", args[0]);
		exit(1);
	}
	if (execve(path, args, envp) == -1)
	{
		freedoublepointer(args);
		free(path);
		ft_printf("Failed to execute command: %s\n", args[0]);
		exit(1);
	}
	freedoublepointer(args);
	free(path);
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
