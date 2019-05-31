/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:56:42 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/04 20:05:00 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	if (s[len] == c)
		return ((char*)&s[len]);
	while (len--)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
	}
	return (NULL);
}
