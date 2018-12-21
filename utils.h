/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:18:36 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 15:05:58 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_tile
{
	unsigned short	lines[4];
	int				width;
	int				height;
	int				col;
	int				row;
}				t_tile;

#endif
