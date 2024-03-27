/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:00:17 by snegi             #+#    #+#             */
/*   Updated: 2023/11/22 12:00:22 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

static size_t	size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

int	memory_allo(char **res, int index, size_t len)
{
	int		i;

	i = 0;
	res[index] = malloc(len);
	if (!res[index])
	{
		while (i < index)
			free(res[i++]);
		free(res);
		return (1);
	}
	return (0);
}

static int	split(char **res, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (memory_allo(res, i, len + 1))
				return (1);
			ft_strlcpy(res[i], s - len, len + 1);
		}
		++i;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**res;

	if (!s || s == NULL)
		return (NULL);
	count = 0;
	count = size(s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[count] = NULL;
	if (split(res, s, c))
		return (NULL);
	return (res);
}
