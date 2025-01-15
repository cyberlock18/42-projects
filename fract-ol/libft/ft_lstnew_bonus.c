/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:20:41 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/26 20:47:59 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_arr;

	new_arr = malloc(sizeof(t_list));
	if (!new_arr)
		return (NULL);
	new_arr->content = content;
	new_arr->next = NULL;
	return (new_arr);
}
