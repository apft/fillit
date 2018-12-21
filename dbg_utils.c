/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:20:30 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 15:54:27 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_utils.h"

void	print_bits(unsigned short nb)
{
	unsigned long	count;
	unsigned short	mask;

	count = sizeof(nb) * 8;
	mask = 1 << (sizeof(nb) * 8 - 1);
	while (count-- > 0) 
		write (1, (mask >> (15 - count) & nb) ? "1" : "0", 1);
}

void	dbg_print_nbr(const char *str, const int n)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putnbr(n);
	ft_putendl(0);
}

void	dbg_print_bin(const unsigned short n)
{
	ft_putstr("dec: ");
	ft_putnbr(n);
	ft_putstr("\nbin: ");
	ft_putnbr_base(n, "01");
	ft_putendl(0);
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
		ft_putstr(" ==========");
		j = -1;
		while (++j < 4)
		{
			ft_putstr("\nline");
			ft_putnbr(j);
			ft_putstr(": ");
			print_bits(tiles[i].lines[j]);
		}
		ft_putendl(0);
		dbg_print_nbr("Height", tiles[i].height);
		dbg_print_nbr("Width", tiles[i].width);
	}
}

void	dbg_print_map(unsigned short *lines)
{
	int i;

	ft_putstr("====== ");
	ft_putstr("MAP");
	ft_putstr("======");
	ft_putendl(0);
	i = -1;
	while (++i < 16)
	{
		print_bits(lines[i]);
		ft_putendl(0);
	}
}

void	dbg_print_str_map(char *str)
{
	ft_putstr("==== ");
	ft_putstr("STR MAP");
	ft_putstr("====");
	ft_putendl(0);
	ft_putstr(str);
}
