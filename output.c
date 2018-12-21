/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:47:48 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 15:00:21 by apion            ###   ########.fr       */
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
	int				start;
	int				j;
	int				h;
	unsigned short	mask;

	if (!str)
		return (0);
	h = -1;
	while (++h < tile->height)
	{
		start = tile->x + (tile->y + h) * (map->n + 1);
		j = -1;
		mask = 1 << (sizeof(mask) * 8 - 1);
		while (++j < 4)
			if (tile->lines[h] & (mask >> j))
				*(str + start + j) = 'A' + i;
	}
	return (1);
}

void	print_solution(const char *str)
{
	print_str(str);	
	free((void *)str);
}
