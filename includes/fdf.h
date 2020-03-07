/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 04:15:12 by srobert-          #+#    #+#             */
/*   Updated: 2019/06/02 15:19:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

# define USAGE			"Usage: ./fdf MAP_FILE"
# define MAP			"Tvoy MAP_FILE govno"
# define MAP_READING	"Soryan chot ne smog prochest'"
# define MAP_INIT		"Chot ne tak s MAP_INIT"
# define FDF_INIT		"Chot ne tak s FDF_INIT"
# define CONV_TO_ARR	"Blya massiv ne sdelalsya"
# define CAMERA_INIT	"Ne camera A Govno"

# define WIDTH 1280
# define HEIGHT 720
# define MENU_WIDTH 50
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))

typedef	enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct				s_map
{
	int						height;
	int						width;
	int						z_min;
	int						z_max;
	int						z_range;
	int						*coord_arr;
	int						*coord_collor;
}							t_map;

typedef struct				s_cam
{
	t_projection			projection;
	int						zoom;
	double					alpha;
	double					beta;
	double					gamma;
	double					z_divisor;
	int						x_offset;
	int						y_offset;
}							t_cam;

typedef struct				s_fdf
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data_addr;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
	t_map					*map;
	t_cam					*camera;
}							t_fdf;

typedef struct				s_coord_values
{
	int						z;
	int						color;
	struct s_coord_values	*next;
}							t_coord_values;

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
	int						color;
}							t_point;

void						next_u_say(char *s);
t_map						*map_init(void);
int							read_map(int fd, t_coord_values **coord_values,
							t_map *map);
int							ft_isnumber(const char *str, int base);
void						push(t_coord_values **coord_stack,
							t_coord_values *new);
void						*pop(t_coord_values **coord_stack);
t_fdf						*fdf_init(t_map *map);
t_cam						*cam_init(t_fdf *fdf);
void						draw(t_map *map, t_fdf *fdf);
t_point						projection(t_point p, t_fdf *fdf);
t_point						new_point(int x, int y, t_map *map);
double						percent(int start, int end, int cur);
int							get_grad_color(t_point cur, t_point start,
							t_point end, t_point delta);
int							get_color(int z, t_map *map);
void						swap_project(t_fdf *fdf);
int							key_press(int key, t_fdf *fdf);
int							close_x(void);
void						move(int key, t_fdf *fdf);
void						rotate(int key, t_fdf *fdf);
void						map_default(t_fdf *fdf);
void						zoom(int key, t_fdf *fdf);
void						flat(int key, t_fdf *fdf);

#endif
