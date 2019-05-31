/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:10:37 by srobert-          #+#    #+#             */
/*   Updated: 2018/11/29 21:14:39 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ss;

	ss = (unsigned char*)s;
	while (n--)
	{
		if (*ss == (unsigned char)c)
			return ((void*)ss);
		else
			ss++;
	}
	return (NULL);
}
