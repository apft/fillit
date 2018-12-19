/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:20:30 by apion             #+#    #+#             */
/*   Updated: 2018/12/19 18:55:22 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_utils.h"

void	dbg_print_nbr(const char *str, const int n)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putnbr(n);
	ft_putendl(0);
}

void	dbg_print_dec(const unsigned short n)
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
		if (tiles[i].line0 < 32768)
			ft_putnbr(0);
		ft_putnbr_base(tiles[i].line0, "01");
		ft_putstr("\nline1: ");
		if (tiles[i].line1 < 32768)
			ft_putnbr(0);
		ft_putnbr_base(tiles[i].line1, "01");
		ft_putstr("\nline2: ");
		if (tiles[i].line2 < 32768)
			ft_putnbr(0);
		ft_putnbr_base(tiles[i].line2, "01");
		ft_putstr("\nline3: ");
		if (tiles[i].line3 < 32768)
			ft_putnbr(0);
		ft_putnbr_base(tiles[i].line3, "01");
		ft_putendl(0);
		i++;
	}
}
