/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:09:18 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/28 22:09:55 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	flag;
	size_t	max;
	size_t	len;

	max = ft_strlen(s1);
	flag = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[flag] != '\0' && ft_isin(s1[flag], set))
		flag++;
	if (s1[flag] == '\0')
		return (ft_strdup(""));
	while (max > flag && ft_isin(s1[max - 1], set))
		max--;
	len = max - flag;
	return (ft_substr(s1, flag, len));
}
