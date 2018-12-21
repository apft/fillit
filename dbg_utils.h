/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:15:55 by apion             #+#    #+#             */
/*   Updated: 2018/12/21 15:54:15 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_UTILS_H
# define DBG_UTILS_H

# include "libft.h"
# include "utils.h"

void	print_bits(unsigned short nb);
void	dbg_print_nbr(const char *str, const int n);
void	dbg_print_bin(const unsigned short n);
void	dbg_print_tiles(const t_tile *tiles, const int k);
void	dbg_print_map(unsigned short *lines);
void	dbg_print_str_map(char *str);

#endif
