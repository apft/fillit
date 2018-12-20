/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:18:36 by apion             #+#    #+#             */
/*   Updated: 2018/12/20 15:21:30 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_tile
{
	unsigned short	lines[4];
	unsigned int	height;
	unsigned int	width;
}				t_tile;

#endif
