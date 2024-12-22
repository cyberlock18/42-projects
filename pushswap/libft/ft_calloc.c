/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:26:41 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/29 18:14:25 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int main(void)
{
	size_t count;
	size_t size;
	int *arr;
	
	count = 5;
	size = sizeof(int);
	
	arr = (int *)ft_calloc(count,size)

	while ()
	printf("%x\n", str);
	free (str);
	return 0;
}*/