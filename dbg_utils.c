/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:20:30 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 15:52:48 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_utils.h"

void	dbg_print_bits(unsigned short nb)
{
	unsigned long	count;
	unsigned short	mask;

	count = sizeof(nb) * 8;
	mask = 1 << (sizeof(nb) * 8 - 1);
	while (count-- > 0)
		write(1, (mask >> (15 - count) & nb) ? "1" : "0", 1);
	ft_putendl(0);
}

void	dbg_print_nbr(const char *str, const int n)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putnbr(n);
	ft_putendl(0);
}

void	dbg_print_map(const t_map *map)
{
	int		j;

	ft_putendl("---- MAP ----");
	dbg_print_nbr("n", map->n);
	j = -1;
	while (++j < map->n)
		dbg_print_bits(map->lines[j]);
	ft_putendl("-------------");
}

void	dbg_print_tile(const t_tile *tile, const int i)
{
	int		j;

	ft_putendl("-------------");
	dbg_print_nbr("tile", i);
	dbg_print_nbr("x", tile->x);
	dbg_print_nbr("y", tile->y);
	dbg_print_nbr("h", tile->height);
	dbg_print_nbr("w", tile->width);
	j = -1;
	while (++j < 4)
		dbg_print_bits(tile->lines[j]);
	ft_putendl("-------------");
}

void	dbg_print_tiles(const t_tile *tiles, const int k)
{
	int		i;
	int		j;

	i = -1;
	while (++i < k)
	{
		ft_putstr("========== ");
		ft_putnbr(i);
		ft_putendl(" ==========");
		j = -1;
		while (++j < 4)
		{
			ft_putstr("line");
			ft_putnbr(j);
			ft_putstr(": ");
			dbg_print_bits(tiles[i].lines[j]);
		}
		ft_putendl(0);
	}
}
