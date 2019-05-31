/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:08:38 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/04 21:01:04 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*hay;
	const char	*ned;

	ned = needle;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		hay = haystack;
		if (*haystack == *needle)
			while (*(needle) != '\0')
			{
				if (*needle != *hay)
				{
					needle = ned;
					break ;
				}
				hay++;
				needle++;
			}
		if (*needle == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
