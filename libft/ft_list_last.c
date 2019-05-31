/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:35:15 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/10 21:39:27 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *head;

	if (!(begin_list))
		return (0);
	if (!(begin_list->next))
		return (begin_list);
	head = begin_list;
	while (head->next)
		head = head->next;
	return (head);
}
