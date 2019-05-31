/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 03:46:08 by srobert-          #+#    #+#             */
/*   Updated: 2019/04/30 08:20:23 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "key_and_color.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

static void	draw_line(t_fdf *fdf, t_point a, t_point b)
{
	t_point delta;
	t_point sign;
	t_point cur;
	int		arr[2];

	delta.x = FT_ABS(b.x - a.x);
	delta.y = FT_ABS(b.y - a.y);
	sign.x = (b.x > a.x) ? 1 : -1;
	sign.y = (b.y > a.y) ? 1 : -1;
	arr[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_grad_color(cur, a, b, delta));
		if ((arr[1] = arr[0] * 2) > -delta.y)
		{
			arr[0] -= delta.y;
			cur.x += sign.x;
		}
		if (arr[1] < delta.x)
		{
			arr[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static void	menu_draw(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, 0xFFFFFF, "MENU:");
	mlx_string_put(fdf->mlx, fdf->win, 100, 20, 0xFFFFFF, "Movement(W/A/S/D)");
	mlx_string_put(fdf->mlx, fdf->win, 400, 20, 0xFFFFFF,
	"Rotate: Z(Q,E), X and Y - Arrows");
	mlx_string_put(fdf->mlx, fdf->win, 850, 20, 0xFFFFFF, "Zoom(+/-)");
	mlx_string_put(fdf->mlx, fdf->win, 1100, 20, 0xFFFFFF,
	"Alignment(</>)");
	mlx_string_put(fdf->mlx, fdf->win, 1350, 20, 0xFFFFFF,
	"Swap Projection(PRESS F)");
	mlx_string_put(fdf->mlx, fdf->win, 1700, 20, 0xFFFFFF, "Set Default(R)");
}

static void	draw_back(t_fdf *fdf)
{
	int *img;
	int i;

	i = -1;
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT);
	img = (int *)fdf->data_addr;
	while (++i < WIDTH * HEIGHT)
		img[i] = (i / WIDTH < MENU_WIDTH) ? MENU_BACKGROUND : BACKGROUND;
}

void		draw(t_map *map, t_fdf *fdf)
{
	int x;
	int y;

	draw_back(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(fdf, projection(new_point(x, y, map), fdf),
				projection(new_point(x + 1, y, map), fdf));
			if (y != fdf->map->height - 1)
				draw_line(fdf, projection(new_point(x, y, map), fdf),
				projection(new_point(x, y + 1, map), fdf));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	menu_draw(fdf);
}
