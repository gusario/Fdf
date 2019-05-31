/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 01:30:58 by srobert-          #+#    #+#             */
/*   Updated: 2019/04/30 01:43:55 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_and_color.h"

void	map_default(t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	fdf->camera->x_offset = 0;
	fdf->camera->y_offset = 0;
	fdf->camera->z_divisor = 1.2;
	fdf->camera->zoom = FT_MIN((WIDTH) / (fdf->map->width * 2),
						HEIGHT / (fdf->map->height * 2));
	draw(fdf->map, fdf);
}
