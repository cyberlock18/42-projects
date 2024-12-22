/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:59:34 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/28 18:44:39 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			s = ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (s);
}
