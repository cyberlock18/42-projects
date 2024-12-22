/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:58:10 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/24 18:59:31 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	bg1;
	size_t	sm1;

	if (little[0] == '\0')
		return ((char *)big);
	if (big == NULL && len == 0)
		return (NULL);
	bg1 = 0;
	while (big[bg1] != '\0' && bg1 < len)
	{
		sm1 = 0;
		while (big[bg1 + sm1] == little[sm1] && (bg1 + sm1) < len)
		{
			if (little[sm1 + 1] == '\0')
				return ((char *)&big[bg1]);
			sm1++;
		}
		bg1++;
	}
	return (NULL);
}
