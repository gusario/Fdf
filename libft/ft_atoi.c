/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:04:52 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/06 21:05:27 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nb)
{
	long long int		res;
	char				negative;

	negative = 0;
	res = 0;
	while (*nb == '\n' || *nb == '\t' || *nb == '\r' || *nb == '\f'
			|| *nb == ' ' || *nb == '\v')
		nb++;
	if (*nb == '-')
		negative = 1;
	if (*nb == '-' || *nb == '+')
		nb++;
	while (*nb != '\n' && *nb != '\t' && *nb != '\r' && *nb != '\f'
			&& *nb != ' ' && *nb != '\v' && (*nb >= '0' && *nb <= '9'))
	{
		res = res * 10 + (*nb - '0');
		if (res < 0 && negative == 1)
			return (0);
		else if (res < 0)
			return (-1);
		nb++;
	}
	if (negative)
		return (-res);
	return (res);
}
