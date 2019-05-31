/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:40:14 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/07 21:23:24 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char tmp;
	unsigned char d;
	unsigned char e;

	tmp = c;
	if (tmp < 128)
		write(fd, &tmp, 1);
	else
	{
		d = 192 + tmp / 64;
		e = 128 + tmp % 64;
		write(fd, &d, 1);
		write(fd, &e, 1);
	}
}
