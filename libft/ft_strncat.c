/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:49:18 by apion             #+#    #+#             */
/*   Updated: 2018/11/21 16:52:25 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(s1 + i))
		i++;
	j = 0;
	while (j < n && *(s2 + j))
		*(s1 + i++) = *(s2 + j++);
	*(s1 + i) = 0;
	return (s1);
}
