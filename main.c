/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:36:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/22 10:22:41 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parser.h"
#include "solver.h"

static int	print_usage(char *exec)
{
	print_str("usage:\t");
	print_str(exec);
	print_str(" file\n");
	return (-1);
}

static int	print_err(int err)
{
	if (err == 1)
		print_str("error: invalid tetrimino\n");
	else if (err == 2)
		print_str("error: invalid character (only '.' and '#')\n");
	else if (err == 3)
		print_str("error: invalid file (columns > 4 characters)\n");
	else if (err == 4)
		print_str("error: invalid file (too long)\n");
	else if (err == 5)
		print_str("error: could not open file\n");
	else if (err == -1)
		print_str("error: could not read from file\n");
	else
		print_str("error\n");
	return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_tile	tiles[26];
	int		k;
	int		err;

	if (ac != 2)
		return (print_usage(av[0]));
	k = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_err(5));
	err = parser(tiles, &k, fd);
	if (err)
		return (print_err(err));
	solver(tiles, k);
	return (0);
}
