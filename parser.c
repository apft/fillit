/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:49:32 by apion             #+#    #+#             */
/*   Updated: 2018/12/19 17:32:12 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#define SIZE 545 // 26*(5*4) + (26-1)

typedef struct	s_parser
{
	unsigned short	tile;
	unsigned short	shift;
}				t_parser;

typedef struct	s_tile
{
	unsigned short	line0;
	unsigned short	line1;
	unsigned short	line2;
	unsigned short	line3;
}				t_tile;

static void	dbg_print_nbr(const char *str, const int n)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putnbr(n);
	ft_putendl(0);
}

static void	bw_print(unsigned short n)
{
	ft_putstr("dec: ");
	ft_putnbr(n);
	ft_putstr("\nbin: ");
	ft_putnbr_base(n, "01");
	ft_putendl(0);
}

static void	print_tiles(t_tile *tiles)
{
	char	i;

	i = 0;
	while (i < 26)
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

static int	create_tile(t_tile *tetrimino, char i, t_parser *tiles)
{
	unsigned short	tile;

	tile = tiles[i].tile;
	ft_putnbr_base(tile, "01");
	ft_putendl(0);
	tetrimino->line0 = (tile >> 12) << 12;
	tetrimino->line1 = ((tile << 4) >> 12) << 12;
	tetrimino->line2 = ((tile << 8) >> 12) << 12;
	tetrimino->line3 = tile << 12;
	return (0);
}

static int	extract_tile(unsigned short tmp, t_tile *tetrimino)
{
	static t_parser		tiles[] =
	{
		{34952, 57344},	// 1000100010001000 1110000000000000
		{61440, 4368},	// 1111000000000000 0001000100010000
		{51328, 56320},	// 1100100010000000 1101110000000000
		{57856, 39296},	// 1110001000000000 1001100110000000
		{17600, 56320},	// 0100010011000000 1101110000000000
		{36352, 39296},	// 1000111000000000 1001100110000000
		{50240, 56320},	// 1100010001000000 1101110000000000
		{59392, 39296},	// 1110100000000000 1001100110000000
		{35008, 56320},	// 1000100011000000 1101110000000000
		{11776, 39296},	// 0010111000000000 1001100110000000
		{52224, 56768},	// 1100110000000000 1101110111000000
		{50688, 39296},	// 1100011000000000 1001100110000000
		{19584, 56320},	// 0100110010000000 1101110000000000
		{27648, 39296},	// 0110110000000000 1001100110000000
		{35904, 56320},	// 1000110001000000 1101110000000000
		{35968, 56320},	// 1000110010000000 1101110000000000
		{19520, 56320},	// 0100110001000000 1101110000000000
		{58368, 39296},	// 1110010000000000 1001100110000000
		{19968, 39296}	// 0100111000000000 1001100110000000
	};
	char	i;
	char	j;
	unsigned short	tile;
	unsigned short	shift;
	unsigned char	bit;

	i = -1;
	if (!tmp)
		return (0);
	while (++i < 19)
	{
		tile = tiles[i].tile;
		shift = tiles[i].shift;
		if (tmp == (tile))
			return (create_tile(tetrimino, i, tiles));
		j = -1;
		while (++j <= 12)
		{
			if (((shift >> (16 - j)) & 1) && tmp == (tile >> j))
			{
				dbg_print_nbr("j", j);
				return (create_tile(tetrimino, i, tiles));
			}
		}
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		r;
	char	buff[SIZE + 1];
	int		i;
	int		j;
	unsigned short	tmp;
	char		error;
	static t_tile	tiles[26];


	ft_putnbr(sizeof(tiles));
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	r = read(fd, buff, SIZE);
	buff[r] = 0;
	dbg_print_nbr("r", r);
	i = 0;
	error = 0;
	tmp = ~0;
	j = 0;
	while (!error && i < r)
	{
		if (i > 0 && i % 21 == 0 && !(error = extract_tile(~tmp, &tiles[j++])))
			tmp = ~0;
		if (i % 21 < 20 && ((i - j) % 5) < 4 && buff[i] != '.' && buff[i] != '#')
			error = 2;
		else if (i % 21 < 20 && ((i - j) % 5) < 4 && buff[i] == '#')
			tmp ^= 1 << (15 - (i % 21) + ((i % 21) / 5));
		if (i % 21 < 20 && ((i - j) % 5) == 4 && buff[i] != '\n')
			error = 3;
		if (i % 21 == 20 && buff[i] != '\n')
			error = 4;
		i++;
	}
	if (!error && !(error = extract_tile(~tmp, &tiles[j])))
		print_tiles(tiles);
	dbg_print_nbr("error", error);
	return (0);
}
