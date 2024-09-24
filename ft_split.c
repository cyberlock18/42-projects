/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:53:14 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/09/23 20:04:25 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// primero contabilizamos
size_t	ft_countWords(char const *s, char c)
{
	size_t	count;
	int		tokn_word;

	count = 0;
	while (*s)
	{
		tokn_word = 0;
		while (*s == c && s != NULL)
			s++;
		while (*s != c && *s)
		{
			if (tokn_word == 0)
			{
				count++;
				tokn_word = 1;
			}
			s++;
		}
	}
	return (count);
}

int	ft_MemSave(char **arrWrd, int i, size_t temp)
{
	arrWrd[i] = malloc(temp);
	if (arrWrd[i] == NULL)
	{
		while (i != 0)
		{
			free(arrWrd[i]);
			i--;
		}
		return (1);
	}
	return (0);
}

int	ft_putS(char **arrWrd, const char *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (ft_MemSave(arrWrd, i, len + 1))
				return (1);
			ft_strlcpy(arrWrd[i], s - len, len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arrWrd;
	size_t	word;

	if (!s)
		return (NULL);
	word = ft_countWords(s, c);
	arrWrd = malloc((word + 1) * sizeof(char *));
	if (!arrWrd)
		return (NULL);
	arrWrd[word] = NULL;
	if (ft_putS(arrWrd, s, c))
		return (NULL);
	return (arrWrd);
}
