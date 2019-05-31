/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:14:49 by srobert-          #+#    #+#             */
/*   Updated: 2019/04/15 18:37:57 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sublen(const char *s, char c)
{
	int i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**matr;

	if (!s)
		return (NULL);
	if (!(matr = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if ((matr[i] = (char*)malloc(sizeof(char) * (ft_sublen(s, c) + 1))))
			{
				ft_strncpy(matr[i], s, ft_sublen(s, c));
				matr[i][ft_sublen(s, c)] = '\0';
				i++;
			}
			s += ft_sublen(s, c);
		}
	}
	matr[i] = 0;
	return (matr);
}
