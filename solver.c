/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:21:15 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/21 18:48:02 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <stdlib.h>
#include "libft.h"
#include "dbg_utils.h"

void	toggle_tile(t_tile *tile, t_map *map)
{
	int		i;

	i = -1;
	while (++i < tile->height)
		(map->lines)[tile->row + i] ^= (tile->lines)[i] >> tile->col;
}

int		check_fit(t_tile *tile, t_map *map)
{
	int		i;
	int		ret;

	ret = 1;
	i = -1;
	while (++i < tile->height && ret)
		if ((tile->lines)[i] >> tile->col & (map->lines)[tile->row + i])
			ret = 0;
	return (ret);
}

int		fill_str_map(t_map *map, t_tile *tile, unsigned int t)
{
	int				line;
	int				col;
	unsigned int	mask;

	line = -1;
	while (++line < tile->height)
	{
		col = -1;
		mask = 1 << 15;
		while (++col < tile->width)
			if (mask >> col & (tile->lines)[line])
				(map->str)[(map->size + 1) * (tile->row + line) +
					tile->col + col] = t + 'A';
	}
	return (1);
}

int		init_str_map(t_map *map)
{
	int		len;
	int		i;

	len = map->size * (map->size + 1);
	if(!(map->str = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	(map->str)[len] = 0;
	i = -1;
	while (++i < len)
	{
		if (!((i + 1) % (map->size + 1)))
			map->str[i] = '\n';
		else
			map->str[i] = '.';
	}
	return (1);
}

int		solver(t_tile *tiles, int t, t_map *map, int nb_tiles)
{
	int		ret;

	if (t == nb_tiles)
		return (init_str_map(map));
	tiles[t].row = 0;
	while (tiles[t].row + tiles[t].height <= map->size)
	{
		tiles[t].col = 0;
		while (tiles[t].col + tiles[t].width <= map->size)
		{
			if (check_fit(&tiles[t], map))
			{
				toggle_tile(&tiles[t], map);
				if ((ret = solver(tiles, t + 1, map, nb_tiles)))
					return ((ret != -1) ? fill_str_map(map, &tiles[t], t) : -1);
				toggle_tile(&tiles[t], map);
			}
			++tiles[t].col;
		}
		++tiles[t].row;
	}
	return (0);
}

int		get_min_map_size(int nb_tiles)
{
	int		size;

	size = 1;
	while (size * size < 4 * nb_tiles)
		++size;
	return (size);
}

int		fillit(t_tile *tiles, t_map *map, int nb_tiles)
{
	int		ret;

	map->size = get_min_map_size(nb_tiles);
	while (!(ret = solver(tiles, 0, map, nb_tiles)))
		map->size++;
	if (ret == -1)
		return (-1);
	ft_putstr(map->str);
	free(map->str);
	return (1);
}
