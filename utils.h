/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:18:36 by apion             #+#    #+#             */
/*   Updated: 2018/12/20 18:08:16 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_tile
{
	unsigned short	lines[4];
	int				width;
	int				height;
	int				x;
	int				y;
}				t_tile;

typedef struct	s_map
{
	unsigned short	lines[16];
	int				n;
}				t_map;

int				n_bits_on(unsigned short v);

#endif
