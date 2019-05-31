/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:20:06 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/10 21:31:26 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;

	if (!begin_list)
		return (0);
	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (0);
}
