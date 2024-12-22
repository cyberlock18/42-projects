/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:52:21 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/10/14 20:14:49 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	aloc_line(char **str_static, char **front)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (str_static[0][i] && str_static[0][i] != '\n')
		i++;
	if (str_static[0][i] == '\n')
		i++;
	*front = ft_substr2(str_static[0], 0, i);
	temp = ft_strdup2(str_static[0] + i);
	free(*str_static);
	*str_static = temp;
}

static char	*read_find(int fd, char *str_static)
{
	int		nb_bytes;
	char	*new_read;
	char	*temp;

	new_read = malloc(BUFFER_SIZE + 1);
	if (!new_read)
		return (NULL);
	nb_bytes = 1;
	while (!ft_strchr2(str_static, '\n') && nb_bytes != 0)
	{
		nb_bytes = read(fd, new_read, BUFFER_SIZE);
		if (nb_bytes < 0)
			return (free(new_read), free(str_static), NULL);
		new_read[nb_bytes] = '\0';
		temp = ft_strjoin2(str_static, new_read);
		free(str_static);
		str_static = temp;
	}
	free(new_read);
	return (str_static);
}

char	*get_next_line(int fd)
{
	static char	*main_str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	main_str = read_find(fd, main_str);
	if (!main_str || main_str[0] == '\0')
		return (free(main_str), main_str = NULL, NULL);
	aloc_line(&main_str, &line);
	return (line);
}

// int main() {
//     int fd = open("hola.txt", O_RDONLY);
//     if (fd == -1) 
// 	{
//         perror("Error abriendo el archivo");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL) 
// 	{
//         printf("%s", line);
//         free(line); 
//     }

//     close(fd);
//     return 0;
// }
