/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:34:31 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/07 19:16:52 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int bignum;

	if (nb < 0)
	{
		ft_putchar('-');
		bignum = nb * -1;
	}
	else
		bignum = nb;
	if (bignum >= 10)
		ft_putnbr(bignum / 10);
	ft_putchar(bignum % 10 + 48);
}
