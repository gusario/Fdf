/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:58:53 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/10 21:16:02 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, \
		void const *content, size_t content_size)
{
	t_list *elem;

	elem = ft_lstnew(content, content_size);
	if (!(*begin_list))
	{
		*begin_list = elem;
		return ;
	}
	elem->next = *begin_list;
	*begin_list = elem;
}
