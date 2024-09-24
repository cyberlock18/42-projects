/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:32:26 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/22 00:03:13 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*sol;

	i = 0;
	sol = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!sol || !f)
		return (NULL);
	while (i < ft_strlen(s))
	{
		sol[i] = (*f)(i, s[i]);
		i++;
	}
	sol[i] = '\0';
	return (sol);
}
