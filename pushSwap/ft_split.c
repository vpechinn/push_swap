/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:32:44 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:56 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_word(char const *str, char c)
{
	char	**array;
	int		i;
	int		count;
	int		n;

	i = 0;
	count = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != c && n == 0)
		{
			count++;
			n = 1;
		}
		if (str[i] == c)
			n = 0;
		i++;
	}
	array = malloc(sizeof(char **) * (count + 1));
	if (!array)
		return (NULL);
	return (array);
}

char	**ft_str(char const *str1, char c, int i)
{
	char	**array;
	int		count;
	int		p;

	array = ft_word(str1, c);
	if (!array)
		return (NULL);
	p = 0;
	while (str1[p])
	{
		if (str1[p] != c)
		{
			count = 0;
			while (str1[p] && str1[p] != c && ++count)
				p++;
			array[i] = ft_substr((str1 + p) - count, 0, count);
			if (!array[i++])
				ft_free(array);
		}
		else
			p++;
	}
	array[i] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	array = ft_str(s, c, i);
	return (array);
}