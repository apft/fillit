/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:21:15 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/21 15:16:52 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solver.h"
# include <stdlib.h>
# include "libft.h"

void	place_tile(t_tile *tile, t_map *map)
{
	int		i;

	i = -1;
	while (++i < tile->height)
		(map->lines)[tile->row + i] |= (tile->lines)[i] >> tile->col;
}

void	remove_tile(t_tile *tile, t_map *map)
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

void	add_newlines(t_map *map)
{
	int	i;

	i = 1;
	while ((i *= 4) < map->size * (map->size + 1))
		map->str[i++] = '\n';
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
				(map->str)[(map->size + 1) * (tile->row + line) + tile->col + col]
					= t + 'A';
	}
	return (1);
}

void	create_str_map(t_map *map)
{
	map->str = (char *)malloc(sizeof(*(map->str)) * map->size * (map->size + 1));
	add_newlines(map);
}

int		solver(t_tile *tiles, int t, t_map *map, int nb_tiles)
{
	if (t == nb_tiles)
	{
		create_str_map(map);
		return (1);
	}
	tiles[t].row = 0;
	while (tiles[t].row + tiles[t].height < map->size)
	{
		tiles[t].col = 0;
		while (tiles[t].col + tiles[t].width < map->size)
		{
			if (check_fit(&tiles[t], map))
			{
				place_tile(&tiles[t], map);
				if (solver(tiles, t + 1, map, nb_tiles))
					return (fill_str_map(map, &tiles[t], t));
				else
					remove_tile(&tiles[t], map);
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

void	fillit(t_tile *tiles, t_map *map, int nb_tiles)
{
	map->size = get_min_map_size(nb_tiles);
	while (!solver(tiles, 0, map, nb_tiles))
		++(map->size);
	ft_putstr(map->str);
}
