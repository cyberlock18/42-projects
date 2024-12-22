/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:16:05 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/24 19:43:30 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*mem;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	mem = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	while (s1[i] != '\0')
	{
		mem[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		mem[j++] = s2[i++];
	}
	mem[j] = '\0';
	return (mem);
}
