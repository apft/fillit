/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:59:47 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 13:54:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		n_bits_on(unsigned short v)
{
	int		c;

	c = 0;
	while (v)
	{
		v &= v - 1;
		c++;
	}
	return (c);
}

int		get_width_max(t_tile *tiles, int k)
{
	int		max;
	int		t_max;

	max = 0;
	t_max = 0;
	while (k--)
	{
		t_max = (tiles[k].height < tiles[k].width) ?
			tiles[k].width : tiles[k].height;
		if (max < t_max) 
			max = t_max;
	}
	return (max);
}
