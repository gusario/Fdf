/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:26:35 by srobert-          #+#    #+#             */
/*   Updated: 2019/04/30 03:09:43 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_and_color.h"

void	swap_project(t_fdf *fdf)
{
	if (fdf->camera->projection == PARALLEL)
		fdf->camera->projection = ISO;
	else if (fdf->camera->projection == ISO)
		fdf->camera->projection = PARALLEL;
	draw(fdf->map, fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_W)
		fdf->camera->y_offset -= 10;
	if (key == MAIN_PAD_S)
		fdf->camera->y_offset += 10;
	if (key == MAIN_PAD_A)
		fdf->camera->x_offset -= 10;
	if (key == MAIN_PAD_D)
		fdf->camera->x_offset += 10;
	draw(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == ARROW_UP)
		fdf->camera->alpha += 0.05;
	if (key == ARROW_DOWN)
		fdf->camera->alpha -= 0.05;
	if (key == ARROW_LEFT)
		fdf->camera->beta += 0.05;
	if (key == ARROW_RIGHT)
		fdf->camera->beta -= 0.05;
	if (key == MAIN_PAD_Q)
		fdf->camera->gamma -= 0.05;
	if (key == MAIN_PAD_E)
		fdf->camera->gamma += 0.05;
	draw(fdf->map, fdf);
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_PLUS)
		fdf->camera->zoom++;
	if (key == MAIN_PAD_MINUS)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf->map, fdf);
}

void	flat(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_MORE && fdf->camera->z_divisor > 0.1)
		fdf->camera->z_divisor -= 0.1;
	if (key == MAIN_PAD_LESS)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor <= 0.1)
		fdf->camera->z_divisor = 0.1;
	draw(fdf->map, fdf);
}
