/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:15:01 by apion             #+#    #+#             */
/*   Updated: 2018/12/19 11:32:36 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	bw_print(short n)
{
	ft_putstr("dec: ");
	ft_putnbr(n);
	ft_putstr("\nbin: ");
	ft_putnbr_base(n, "01");
	ft_putendl(0);
}

int		main(void)
{
	short	tmp;
	char	*str;
	int		i;
	int		error;

	str = "####\n....\n....\n....\n" ;
	str = ".#..\n##t.\n#...\n....\n" ;
	tmp = -1;
	ft_putstr("sizeof short: ");
	ft_putnbr((int)sizeof(tmp));
	ft_putendl(0);
	bw_print(tmp);
	tmp ^= 1 << 1;
	bw_print(tmp);
	bw_print(tmp << 2);
	ft_putendl(str);
	i = 0;
	error = 0;
	while (!error && *(str + i))
	{
		if (i % 21 == 0)
			tmp = -1;
		if (i % 21 < 20 && i % 5 < 4 && str[i] != '.' && str[i] != '#')
			error = 1;
		else if (i % 21 < 20 && i % 5 < 4 && str[i] == '#')
		{
			ft_putendl("found #");
			bw_print(1 << (15 - (i % 21) + ((i % 21) / 5)));
			tmp ^= 1 << (15 - (i % 21) + ((i % 21) / 5));
		}
		if (i % 21 < 20 && i % 5 == 4 && str[i] != '\n')
			error = 1;
		if (i % 21 == 20 && str[i] != '\n')
			error = 1;
		i++;
		bw_print(~tmp);
	}
	ft_putstr("error: ");
	ft_putnbr(error);
	ft_putendl(0);
	return (0);
}
