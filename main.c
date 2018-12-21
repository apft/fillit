/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:36:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 18:51:13 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parser.h"
#include "solver.h"
#include "dbg_utils.h"

void	init_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < 16)
		(map->lines[i]) = 0;
	map->size = 0;
	map->str = 0;
}

int		main(int ac, char **av)
{
	int		fd;
	t_tile	tiles[26];
	t_map	map;
	int		k;
	int		ret;

	k = 0;
	fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = parser(tiles, &k, fd);
	//dbg_print_nbr("ret", ret);
	//if (ret == 0)
	//	dbg_print_tiles(tiles, k);
	if (fillit(tiles, &map, k) == -1)
		ft_putendl("Map str allocation failed");
	return (0);
}
