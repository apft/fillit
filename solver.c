/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:11:19 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 15:26:54 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "output.h"
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
				print_solution(out);
			return (1);
		}
		if (fill)
			remove_tile(map, &tiles[i]);
		move_tile(map->n, &tiles[i]);
	}
	return (0);
}

int			solver(t_tile *tiles, int k)
{
	static t_map	map;
	int				fill;

	map.n = get_width_max(tiles, k);
	while (map.n * map.n < 4 * k)
		map.n++;
	while (!(fill = fillit(&map, tiles, k, 0)))
		map.n++;
	return (0);
}
