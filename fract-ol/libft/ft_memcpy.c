/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:31:07 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/22 22:28:26 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (src == NULL && dest == NULL)
		return (dest);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (n > 0)
	{
		*(temp_dest++) = *(temp_src++);
		n--;
	}
	return (dest);
}
