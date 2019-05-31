/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   urges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 04:08:55 by srobert-          #+#    #+#             */
/*   Updated: 2019/04/30 04:11:22 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_and_color.h"
#include "libft.h"

void	next_u_say(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

double	percent(int start, int end, int cur)
{
	double place;
	double dist;

	place = cur - start;
	dist = end - start;
	if (!dist)
		return (1.0);
	else
		return (place / dist);
}

int		get_grad_color(t_point cur, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	int		final_color;
	double	percentage;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, cur.x);
	else
		percentage = percent(start.y, end.y, cur.y);
	red = (int)(((start.color >> 16) & 0xFF) * (1 - percentage) +
			((end.color >> 16) & 0xFF) * percentage);
	green = (int)(((start.color >> 8) & 0xFF) * (1 - percentage) +
			((end.color >> 8) & 0xFF) * percentage);
	blue = (int)((start.color & 0xFF) * (1 - percentage) +
			(end.color & 0xFF) * percentage);
	final_color = (red << 16) | (green << 8) | blue;
	return (final_color);
}

int		get_color(int z, t_map *map)
{
	double percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.3)
		return (RED);
	else if (percentage < 0.7)
		return (BLUE);
	else
		return (WHITE);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	p;
	int		index;

	index = y * map->width + x;
	p.x = x;
	p.y = y;
	p.z = map->coord_arr[index];
	p.color = (map->coord_collor[1] == -1) ?
				get_color(p.z, map) : map->coord_collor[index];
	return (p);
}
