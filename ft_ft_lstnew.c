/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:20:41 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/22 22:36:40 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_Arr;

	new_Arr = malloc(sizeof(t_list));
	if (!new_Arr)
		return (NULL);
	new_Arr->content = content;
	new_Arr->next = NULL;
	return (new_Arr);
}
