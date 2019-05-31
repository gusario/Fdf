/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:52:31 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/04 19:35:26 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_l;
	size_t src_l;
	size_t i;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	if (dst && src)
	{
		if (size < dst_l)
			return (size + src_l);
		while (src[i] != '\0' && (dst_l + i + 1) < size)
		{
			dst[dst_l + i] = src[i];
			i++;
		}
		dst[dst_l + i] = '\0';
	}
	return (dst_l + src_l);
}
