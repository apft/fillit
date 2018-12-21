/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:36:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 19:01:11 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parser.h"
#include "solver.h"
#include "errors.h"

static int	print_usage(void)
{
	print_str("usage:\tfillit file\n");
	return (-1);
}

static int	print_err(int err)
{
	if (err == ERR_TILE)
		print_str("error: invalid tetrimino\n");
	else if (err == ERR_CHAR)
		print_str("error: invalid character (only '.' and '#')\n");
	else if (err == ERR_FILE)
		print_str("error: invalid file (columns > 4 characters)\n");
	else if (err == ERR_FILE_SIZE)
		print_str("error: invalid file (too long)\n");
	else if (err == ERR_OPEN)
		print_str("error: could not open file\n");
	else if (err == ERR_READ)
		print_str("error: could not read from file\n");
	else if (err == ERR_MALLOC)
		print_str("error: not sufficient space to malloc\n");
	else
		print_str("error\n");
	return (-1);
}

int			main(int ac, char **av)
{
	int		fd;
	t_tile	tiles[26];
	int		k;
	int		err;

	if (ac != 2)
		return (print_usage());
	k = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_err(ERR_OPEN));
	err = parser(tiles, &k, fd);
	if (err)
		return (print_err(err));
	if ((err = solver(tiles, k)) != 1)
		print_err(err);
	return (0);
}
