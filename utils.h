/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:18:36 by apion             #+#    #+#             */
/*   Updated: 2018/12/20 15:43:18 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_tile
{
	unsigned short	lines[4];
	short			width;
	short			height;
}				t_tile;

typedef struct	s_map
{
	unsigned short	lines[16];
	short			n;
}				t_map;

#endif
