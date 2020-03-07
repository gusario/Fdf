/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 03:53:02 by srobert-          #+#    #+#             */
/*   Updated: 2019/06/01 13:31:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

t_map	*map_init(void)
{
	t_map *map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		next_u_say(MAP_INIT);
	map->height = 0;
	map->width = 0;
	map->coord_arr = NULL;
	map->coord_collor = NULL;
	map->z_min = 2147483647;
	map->z_max = -2147483648;
	map->z_range = 0;
	return (map);
}

t_cam	*cam_init(t_fdf *fdf)
{
	t_cam *cam;

	if (!(cam = (t_cam *)ft_memalloc(sizeof(t_cam))))
		next_u_say(CAMERA_INIT);
	cam->zoom = FT_MIN((WIDTH) / (fdf->map->width * 2),
				HEIGHT / (fdf->map->height * 2));
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->z_divisor = 3;
	cam->x_offset = 0;
	cam->y_offset = 0;
	return (cam);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		next_u_say(FDF_INIT);
	if (!(fdf->mlx = mlx_init()))
		next_u_say(FDF_INIT);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF")))
		next_u_say(FDF_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		next_u_say(FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
					&fdf->size_line, &(fdf->endian));
	fdf->map = map;
	return (fdf);
}
