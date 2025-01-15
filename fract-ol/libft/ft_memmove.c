/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:26:41 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/25 20:34:04 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (temp_src < temp_dest && temp_dest < temp_src + length)
	{
		while (length--)
			temp_dest[length] = temp_src[length];
	}
	else
	{
		i = 0;
		while (i < length)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}
