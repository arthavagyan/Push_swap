/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 22:47:12 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/09 20:27:10 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	**free_calloc(char **res, size_t i)
{
	while (i > 0)
	{
		free(res[i - 1]);
		i--;
	}
	free(res);
	return (NULL);
}

static size_t	num_w(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	len_w(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = ft_calloc(num_w(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = ft_calloc(len_w(&s[i], c) + 1, sizeof(char));
			if (!res[j])
				return (free_calloc(res, j));
			ft_strlcpy(res[j++], &s[i], len_w(&s[i], c) + 1);
			i += len_w(&s[i], c);
		}
		else
			i++;
	}
	return (res);
}
