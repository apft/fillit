/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:15:55 by apion             #+#    #+#             */
/*   Updated: 2018/12/19 18:56:13 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_UTILS_H
# define DBG_UTILS_H

# include "libft.h"
# include "utils.h"

void	dbg_print_nbr(const char *str, const int n);
void	dbg_print_bin(const unsigned short n);
void	dbg_print_tiles(const t_tile *tiles, const int k);

#endif
