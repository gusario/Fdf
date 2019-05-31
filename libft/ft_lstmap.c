/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:57:24 by srobert-          #+#    #+#             */
/*   Updated: 2018/12/10 20:35:40 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	just_free(void *lst, size_t size)
{
	size = 0;
	free(lst);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *beglist;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	beglist = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			ft_lstdel(&beglist, just_free);
			return (NULL);
		}
		list = list->next;
	}
	return (beglist);
}
