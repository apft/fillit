/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:07:55 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 18:38:09 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define MAP_MAX 545
# define SIZE 550

# include "utils.h"

typedef struct	s_parser
{
	unsigned short	tile;
	unsigned short	shift;
}				t_parser;

int				parser(t_tile *tiles, int *k, const int fd);

#endif
