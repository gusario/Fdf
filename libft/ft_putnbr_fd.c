/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:47:58 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/07 19:17:59 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int bignum;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		bignum = nb * -1;
	}
	else
		bignum = nb;
	if (bignum >= 10)
		ft_putnbr_fd(bignum / 10, fd);
	ft_putchar_fd(bignum % 10 + 48, fd);
}
