/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:27:47 by srobert-          #+#    #+#             */
/*   Updated: 2019/04/30 03:44:15 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_and_color.h"

int	key_press(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == MAIN_PAD_F)
		swap_project(fdf);
	else if (key == MAIN_PAD_W || key == MAIN_PAD_S ||
			key == MAIN_PAD_A || key == MAIN_PAD_D)
		move(key, fdf);
	else if (key == ARROW_UP || key == ARROW_DOWN ||
			key == ARROW_LEFT || key == ARROW_RIGHT || key == MAIN_PAD_Q ||
			key == MAIN_PAD_E)
		rotate(key, fdf);
	else if (key == MAIN_PAD_R)
		map_default(fdf);
	else if (key == MAIN_PAD_PLUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == MAIN_PAD_MORE || key == MAIN_PAD_LESS)
		flat(key, fdf);
	return (0);
}

int	close_x(void)
{
	exit(0);
}
