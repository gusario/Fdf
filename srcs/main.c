/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:08:37 by david             #+#    #+#             */
/*   Updated: 2019/04/30 03:56:55 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	int				fd;
	t_map			*map;
	t_fdf			*fdf;
	t_coord_values	*coord_stack;

	errno = 0;
	coord_stack = NULL;
	if (argc != 2)
		next_u_say(GOVNO_USAGE);
	if (!(fd = open(argv[1], O_RDONLY)))
		next_u_say(GOVNO_MAP);
	map = map_init();
	if (read_map(fd, &coord_stack, map) == -1)
		next_u_say(GOVNO_MAP_READING);
	fdf = fdf_init(map);
	fdf->camera = cam_init(fdf);
	draw(map, fdf);
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, close_x, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
