/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:36:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/19 19:21:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parser.h"
#include "dbg_utils.h"

int		main(int ac, char **av)
{
	int		fd;
	t_tile	tiles[26];
	int		k;
	int		ret;

	k = 0;
	fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = parser(tiles, &k, fd);
	dbg_print_nbr("ret", ret);
	if (ret == 0)
		dbg_print_tiles(tiles, k);
	return (0);
}
