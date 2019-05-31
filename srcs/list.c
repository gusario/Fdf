/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 03:55:00 by srobert-          #+#    #+#             */
/*   Updated: 2019/04/30 03:55:58 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	push(t_coord_values **coord_stack, t_coord_values *new)
{
	if (coord_stack)
	{
		if (new)
			new->next = *coord_stack;
		*coord_stack = new;
	}
}

void	*pop(t_coord_values **coord_stack)
{
	t_coord_values *top;

	top = NULL;
	if (coord_stack && *coord_stack)
	{
		top = *coord_stack;
		*coord_stack = (*coord_stack)->next;
	}
	return (top);
}
