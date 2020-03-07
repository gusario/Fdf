/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 04:03:33 by srobert-          #+#    #+#             */
/*   Updated: 2019/06/01 13:33:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void				feel_free(char **buf)
{
	int i;

	i = -1;
	while (buf[++i])
		free(buf[i]);
	free(buf);
}

static t_coord_values	*new_coord(char *s)
{
	t_coord_values	*coord;
	char			**parts;

	if (!(coord = (t_coord_values*)ft_memalloc(sizeof(t_coord_values))))
		next_u_say(MAP_READING);
	if (!(parts = ft_strsplit(s, ',')))
		next_u_say(MAP_READING);
	if (!ft_isnumber(parts[0], 10))
		next_u_say(MAP_READING);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		next_u_say(MAP_READING);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	feel_free(parts);
	return (coord);
}

static void				parse_line(char **coords_line,
						t_coord_values **coord_values, t_map *map)
{
	int width;

	width = 0;
	while (*coords_line)
	{
		push(coord_values, new_coord(*coords_line++));
		width++;
	}
	if (map->width == 0)
		map->width = width;
	else if (map->width != width)
		next_u_say(MAP);
}

static void				translate(t_coord_values **coord_values, t_map *map)
{
	int				i;
	size_t			arr_size;
	t_coord_values	*coord;

	arr_size = map->width * map->height * sizeof(int);
	i = map->width * map->height - 1;
	if (!(map->coord_arr = (int *)ft_memalloc(arr_size)))
		next_u_say(CONV_TO_ARR);
	if (!(map->coord_collor = (int *)ft_memalloc(arr_size)))
		next_u_say(CONV_TO_ARR);
	while ((coord = pop(coord_values)) && i >= 0)
	{
		map->coord_arr[i] = coord->z;
		map->coord_collor[i] = coord->color;
		if (map->z_max < coord->z)
			map->z_max = coord->z;
		if (map->z_min > coord->z)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}

int						read_map(int fd, t_coord_values **coord_values,
								t_map *map)
{
	char	*line;
	char	**coords_line;
	int		result;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords_line = ft_strsplit(line, ' ')))
			next_u_say(MAP_READING);
		parse_line(coords_line, coord_values, map);
		feel_free(coords_line);
		ft_strdel(&line);
		map->height++;
	}
	if (!(*coord_values))
		next_u_say(MAP);
	translate(coord_values, map);
	return (result);
}
