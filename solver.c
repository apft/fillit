/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:11:19 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 13:35:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "libft.h"
#include "dbg_utils.h"

static int	add_tile(t_map *map, t_tile *tile)
{
	int		err;
	int		h;
	int		x;
	int		y;

	err = 0;
	h = tile->height;
	x = tile->x;
	y = tile->y;
	if ((y + tile->height) > map->n)
		return (0);
	while (h-- && !err)
		err = map->lines[y + h] & (tile->lines[h] >> x);
	if (!err)
	{
		h = tile->height;
		while (h--)
			map->lines[h + y] |= (tile->lines[h] >> x);
	}
	return (!err);
}

static void	remove_tile(t_map *map, t_tile *tile)
{
	int		h;
	int		x;
	int		y;

	h = tile->height;
	x = tile->x;
	y = tile->y;
	while (h--)
		map->lines[h + y] ^= (tile->lines[h] >> x);
}

static void	move_tile(int n, t_tile *tile)
{
	if (tile->x + tile->width < n)
		tile->x++;
	else
	{
		tile->x = 0;
		tile->y++;
	}
}

static char	*init_str(int n)
{
	char	*str;
	int		i;
	int		l;

	l = n * (n + 1);
	str = (char *)malloc(sizeof(*str) * (l + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < l)
	{
		if (i > 0 && (i + 1) % (n + 1) == 0)
			*(str + i) = '\n';
		else
			*(str + i) = '.';
	}
	*(str + i) = 0;
	return (str);
}

static int	set_char(char *str, t_tile *tile, int i, t_map *map)
{
	int		h;
	int		x;
	int		y;
	int		start;
	int		j;
	unsigned short	mask;

	x = tile->x;
	y = tile->y;
	if (!str)
		return (0);
	h = 0;
	while (h < tile->height)
	{
		start = x + (y + h) * (map->n + 1);
		j = 0;
		mask = 1 << (sizeof(mask) * 8 - 1);
		while (j < 4)
		{
			if (tile->lines[h] & (mask >> j))
				*(str + start + j) = 'A' + i;
			j++;
		}
		h++;
	}
	return (1);
}

static int	fillit(t_map *map, t_tile *tiles, int k, int i)
{
	static char		*out;
	int				fill;
	int				y;

	if (i == k)
	{
		out = init_str(map->n);
		return (1);
	}
	tiles[i].x = 0;
	tiles[i].y = 0;
	while ((tiles[i].y + tiles[i].height) <= map->n)
	{
		if ((fill = add_tile(map, &tiles[i])) && fillit(map, tiles, k, i + 1))
		{
			set_char(out, &tiles[i], i, map);
			if (i == 0)
				ft_putstr(out);
			return (1);
		}
		if (fill)
			remove_tile(map, &tiles[i]);
		if (i == 0)
			return (0);
		move_tile(map->n, &tiles[i]);
	}
	return (0);
}

static int	get_width_max(t_tile *tiles, int k)
{
	int		max;
	int		t_max;

	max = 0;
	t_max = 0;
	while (k--)
	{
		t_max = (tiles[k].height < tiles[k].width) ?
			tiles[k].width : tiles[k].height;
		if (max < t_max) 
			max = t_max;
	}
	return (max);
}

int			solver(t_tile *tiles, int k)
{
	static t_map	map;
	int				fill;

	map.n = get_width_max(tiles, k);
	dbg_print_nbr("k", k);
	while (map.n * map.n < 4 * k)
		map.n++;
	while (!(fill = fillit(&map, tiles, k, 0)))
	{
		dbg_print_nbr("n", map.n);
		map.n++;
	}
	return (0);
}
