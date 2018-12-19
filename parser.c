/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:49:32 by apion             #+#    #+#             */
/*   Updated: 2018/12/19 20:00:46 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "dbg_utils.h"

static int	active_bit(unsigned short v)
{
	unsigned char	c;

	c = 0;
	while (v)
	{
		v &= v - 1;
		c++;
	}
	return (c);
}

static int	create_tile(t_tile *tetrimino, char i, t_parser *tiles)
{
	unsigned short	tile;

	tile = tiles[i].tile;
	tetrimino->line0 = (tile >> 12) << 12;
	tetrimino->line1 = ((tile << 4) >> 12) << 12;
	tetrimino->line2 = ((tile << 8) >> 12) << 12;
	tetrimino->line3 = tile << 12;
	return (0);
}

static int	extract_tile(unsigned short tmp, t_tile *tetrimino)
{
	char				i;
	char				j;
	unsigned short		tile;
	unsigned short		shift;
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

	if (!tmp || active_bit(tmp) != 4)
		return (1);
	i = -1;
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
				return (create_tile(tetrimino, i, tiles));
		}
	}
	return (1);
}

int			parser(t_tile *tiles, int *k, const int fd)
{
	char			buf[SIZE + 1];
	ssize_t			r;
	int				i;
	char			err;
	unsigned short	tmp;

	if ((r = read(fd, buf, SIZE)) < 0 || r > MAP_MAX)
		return (-1);
	buf[r] = 0;
	tmp = ~0;
	err = 0;
	i = -1;
	while (!err && ++i < r)
	{
		if (i > 0 && i % 21 == 0 && !(err = extract_tile(~tmp, &tiles[(*k)++])))
			tmp = ~0;
		if (i % 21 < 20 && ((i - *k) % 5) < 4 && buf[i] != '.' && buf[i] != '#')
			return (2);
		else if (i % 21 < 20 && ((i - *k) % 5) < 4 && buf[i] == '#')
			tmp ^= 1 << (15 - (i % 21) + ((i % 21) / 5));
		if (i % 21 < 20 && ((i - *k) % 5) == 4 && buf[i] != '\n')
			return (3);
		if (i % 21 == 20 && buf[i] != '\n')
			return (4);
	}
//	if (!err && i >= 20)
//		err = extract_tile(~tmp, &tiles[(*k)++]);
//	return (err);
	return (err || i < 20 || !(r % 21) || extract_tile(~tmp, &tiles[(*k)++]));
}
