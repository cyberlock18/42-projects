/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:53:14 by ruortiz-          #+#    #+#             */
/*   Updated: 2024/11/02 18:04:23 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwrds(char const *s, char c)
{
	size_t	count;
	int		in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	ft_free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static int	ft_memsave(char **arrWrd, int i, size_t temp)
{
	arrWrd[i] = malloc(temp);
	if (arrWrd[i] == NULL)
	{
		ft_free_arr(arrWrd, i - 1);
		return (1);
	}
	return (0);
}

static int	ft_puts(char **arrwrd, const char *s, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (ft_memsave(arrwrd, i, len + 1))
				return (1);
			ft_strlcpy(arrwrd[i], s - len, len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**arrwrd;

	if (!s)
		return (NULL);
	word_count = ft_countwrds(s, c);
	arrwrd = malloc((word_count + 1) * sizeof(char *));
	if (!arrwrd)
		return (NULL);
	arrwrd[word_count] = NULL;
	if (ft_puts(arrwrd, s, c))
	{
		ft_free_arr(arrwrd, word_count - 1);
		return (NULL);
	}
	return (arrwrd);
}
// #include <stdio.h>

// int main(void)
// {
// 	char	str[] = "          hola    how   is   it            ";
// 	char	**arr;
// 	int	i;
// 	arr = ft_split(str, ' ');
// 	while (i < 3)
// 	{
// 		printf("la palabra numero %d es: %s\n", i, arr[i]);
// 		free (arr[i]);
// 		i++;
// 	}
// 	free (arr);
// 	return (0);
// }
