/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:05:23 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/23 20:41:05 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_lengt;
	size_t	dest_lengt;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	src_lengt = ft_strlen(src);
	dest_lengt = ft_strlen(dst);
	if (dst == NULL)
		return (src_lengt);
	i = 0;
	if (size <= dest_lengt || size == 0)
		return (size + src_lengt);
	while (src[i] != '\0' && (dest_lengt + i) < (size - 1))
	{
		dst[dest_lengt + i] = src[i];
		i++;
	}
	dst[dest_lengt + i] = '\0';
	return (dest_lengt + src_lengt);
}
