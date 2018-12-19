/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:49:32 by apion             #+#    #+#             */
/*   Updated: 2018/12/19 14:46:03 by apion            ###   ########.fr       */
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
	char	line0 : 4;
	char	line1 : 4;
	char	line2 : 4;
	char	line3 : 4;
}				t_tile;

static void	bw_print(short n)
{
	ft_putstr("dec: ");
	ft_putnbr(n);
	ft_putstr("\nbin: ");
	ft_putnbr_base(n, "01");
	ft_putendl(0);
}

static int	extract_tile(short tmp)
{
	static t_parser		tiles[] =
	{
		{2184, 24576},	// 1000100010001000 1110000000000000
		{28672, 4368},	// 1111000000000000 0001000100010000
		{18560, 23552},	// 1100100010000000 1101110000000000
		{25088, 6528},	// 1110001000000000 1001100110000000
		{17600, 23552},	// 0100010011000000 1101110000000000
		{3584, 6528},	// 1000111000000000 1001100110000000
		{17472, 23552},	// 1100010001000000 1101110000000000
		{26624, 6528},	// 1110100000000000 1001100110000000
		{2240, 23552},	// 1000100011000000 1101110000000000
		{11776, 6528},	// 0010111000000000 1001100110000000
		{19456, 24000},	// 1100110000000000 1101110111000000
		{17920, 6528},	// 1100011000000000 1001100110000000
		{19584, 23552},	// 0100110010000000 1101110000000000
		{27648, 6528},	// 0110110000000000 1001100110000000
		{3136, 23552},	// 1000110001000000 1101110000000000
		{3200, 23552},	// 1000110010000000 1101110000000000
		{19520, 23552},	// 0100110001000000 1101110000000000
		{25600, 6528},	// 1110010000000000 1001100110000000
		{19968, 6528}	// 0100111000000000 1001100110000000
	};
	char	i;
	char	j;
	unsigned short	tile;
	unsigned short	shift;
	char	bit;

	i = -1;
	bw_print(tmp);
	if (!tmp)
		return (0);
	while (++i < 19)
	{
		tile = tiles[i].tile;
		shift = tiles[i].shift;
		j = 0;
		while (++j <= 12)
		{
			bit = (j >> shift) & -1;
			if (bit)
				ft_putnbr(j);
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
	unsigned short	tmp;
	int		error;


	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	r = read(fd, buff, SIZE);
	buff[r] = 0;
	ft_putendl(buff);
	i = 0;
	error = 0;
	tmp = ~0;
	while (!error && i < r)
	{
		if (i % 21 == 0 && (error = extract_tile(~tmp)) == 0)
			tmp = ~0;
		if (i % 21 < 20 && i % 5 < 4 && buff[i] != '.' && buff[i] != '#')
			error = 1;
		else if (i % 21 < 20 && i % 5 < 4 && buff[i] == '#')
			tmp ^= 1 << (15 - (i % 21) + ((i % 21) / 5));
		if (i % 21 < 20 && i % 5 == 4 && buff[i] != '\n')
			error = 1;
		if (i % 21 == 20 && buff[i] != '\n')
			error = 1;
		i++;
	}
	bw_print(~tmp);
	ft_putstr("error: ");
	ft_putnbr(error);
	ft_putendl(0);
	return (0);
}
