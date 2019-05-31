/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:04:14 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/06 19:04:29 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i + j] == needle[j])
			while (haystack[i + j] == needle[j] &&
					(i + j) <= len && haystack[i + j])
				j++;
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
