/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:11:19 by apion             #+#    #+#             */
/*   Updated: 2018/12/20 18:39:38 by apion            ###   ########.fr       */
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
	if (y + h >= map->n)
		return (0);
	while (h && !(err = map->lines[h + y] & (tile->lines[h] >> x)))
		h--;
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

static int	set_char(char *str, t_tile *tile, int i, char c)
{
	int		x;
	int		y;
	int		start;

	x = tile->x;
	y = tile->y;
	start = 2 * (y + 1) * x;
	return (1);
}

static int	fillit(t_map *map, t_tile *tiles, int k, int i)
{
	static char		*out;
	int				fill;
	int				y;

	dbg_print_nbr("i", i);
	if (i == k)
	{
		out = init_str(map->n);
		return (1);
	}
	tiles[i].x = 0;
	tiles[i].y = 0;
	while ((tiles[i].y + tiles[i].height) < map->n)
	{
		if (add_tile(map, &tiles[i]) && fillit(map, tiles, k, i + 1))
		{
			set_char(out, &tiles[i], i, 'A' + i);
			if (out)
				ft_putstr(out);
			return (1);
		}
		remove_tile(map, &tiles[i]);
		move_tile(map->n, &tiles[i]);
	}
	return (0);
}


int			solver(t_tile *tiles, int k)
{
	t_map	map;
	int		fill;

	dbg_print_nbr("k", k);
	map.n = 2;
	while (4 * k < map.n * map.n)
		map.n++;
	dbg_print_nbr("n", map.n);
	while (!(fill = fillit(&map, tiles, k, 0)))
	{
		dbg_print_nbr("n", map.n);
		dbg_print_nbr("fill", fill);
		map.n++;
	}
		dbg_print_nbr("n", map.n);
		dbg_print_nbr("fill", fill);
	return (0);
}
