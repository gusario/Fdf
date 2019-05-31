/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:08:44 by srobert-          #+#    #+#             */
/*   Updated: 2018/11/26 22:23:41 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sorc;

	dest = (unsigned char*)dst;
	sorc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sorc[i];
		if (sorc[i] == (unsigned char)c)
			return ((void*)&dest[i + 1]);
		i++;
	}
	return (NULL);
}
