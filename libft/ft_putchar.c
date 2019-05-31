/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:12:20 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/07 21:19:08 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char tmp;
	unsigned char d;
	unsigned char e;

	tmp = c;
	if (tmp < 128)
		write(1, &c, 1);
	else
	{
		d = 192 + tmp / 64;
		e = 128 + tmp % 64;
		write(1, &d, 1);
		write(1, &e, 1);
	}
}
