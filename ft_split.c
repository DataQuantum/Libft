/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:27:07 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/07 14:08:58 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static char	**free_mem(char **array, size_t i)
{
	while (i > 0)
	{
		free(array[i - 1]);
		i--;
	}
	free(array);
	return (NULL);
}

static char	**fill_array(char **array, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		len = 0;
		while (s[len] != c && s[len])
			len++;
		array[i] = ft_substr(s, 0, len);
		if (!array[i])
			return (free_mem(array, i));
		s = s + len;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = words_count(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (fill_array(array, s, c, words));
}
