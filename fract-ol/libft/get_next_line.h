/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:50:21 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/10/14 20:15:30 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen2(const char *s);
char	*ft_strdup2(const char *s1);
char	*ft_substr2(const char *s, unsigned int start, size_t len);
char	*ft_strjoin2(const char *s1, const char *s2);
int		ft_strchr2(const char *s, int c);

#endif