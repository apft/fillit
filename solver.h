/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:21:27 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/21 15:17:07 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "utils.h"

typedef struct			s_map{
	unsigned short		lines[16];
	int					size;
	char				*str;
}						t_map;

void	fillit(t_tile *tiles, t_map *map, int nb_tiles);

# endif
