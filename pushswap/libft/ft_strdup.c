/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:16:13 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/27 22:17:45 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	size_t	i;

	i = 0;
	cp = (char *)malloc(ft_strlen(s) + 1);
	if (cp == NULL)
		return (NULL);
	while (s[i])
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
