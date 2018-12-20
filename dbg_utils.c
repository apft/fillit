/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:20:30 by apion             #+#    #+#             */
/*   Updated: 2018/12/20 14:26:42 by jkettani         ###   ########.fr       */
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
	char	i;

	i = 0;
	while (i < k)
	{
		ft_putstr("========== ");
		ft_putnbr(i);
		ft_putstr(" ==========");
		ft_putstr("\nline0: ");
		print_bits(tiles[i].line0);
		ft_putstr("\nline1: ");
		print_bits(tiles[i].line1);
		ft_putstr("\nline2: ");
		print_bits(tiles[i].line2);
		ft_putstr("\nline3: ");
		print_bits(tiles[i].line3);
		ft_putendl(0);
		i++;
	}
}
