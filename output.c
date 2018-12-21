/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:47:48 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 13:59:20 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

char	*init_str(int n)
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

int		set_char(char *str, t_tile *tile, int i, t_map *map)
{
	int		h;
	int		x;
	int		y;
	int		start;
	int		j;
	unsigned short	mask;

	x = tile->x;
	y = tile->y;
	if (!str)
		return (0);
	h = 0;
	while (h < tile->height)
	{
		start = x + (y + h) * (map->n + 1);
		j = 0;
		mask = 1 << (sizeof(mask) * 8 - 1);
		while (j < 4)
		{
			if (tile->lines[h] & (mask >> j))
				*(str + start + j) = 'A' + i;
			j++;
		}
		h++;
	}
	return (1);
}
