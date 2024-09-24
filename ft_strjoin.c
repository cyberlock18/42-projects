/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:16:05 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/20 23:47:26 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ans;

	i = 0;
	j = 0;
	ans = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ans[i] == '\0')
		return (NULL);
	while (s1[i] != '\0')
		ans[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		ans[j++] = s2[i];
	ans[j] = '\0';
	return (ans);
}
