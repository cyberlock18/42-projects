/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:26:41 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/23 20:34:55 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char *temp_dest;
	const unsigned char *temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);

	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;

	if (temp_src < temp_dest && temp_dest < temp_src + length)
	{
		while (length--)
			temp_dest[length] = temp_src[length];
	}
	else
	{
		for (size_t i = 0; i < length; i++)
			temp_dest[i] = temp_src[i];
	}

	return (dest);
}