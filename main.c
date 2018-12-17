/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:54:05 by jkettani          #+#    #+#             */
/*   Updated: 2018/12/17 18:47:53 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void		print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i;
	int j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
		printf(" ");
    }
    puts("");
}

void		print_res(unsigned int i, unsigned int j, unsigned int k)
{
	print_bits(sizeof(i), &i);
	print_bits(sizeof(j), &j);
	print_bits(sizeof(k), &k);
}

void		and_opp(unsigned int i, unsigned int j)
{
	unsigned int		k;

	k = i & j;
	printf("AND operator (&):\n");	
	print_res(i, j, k);
}

void		or_opp(unsigned int i, unsigned int j)
{
	unsigned int		k;

	k = i | j;
	printf("OR operator (|):\n");	
	print_res(i, j, k);
}

void		xor_opp(unsigned int i, unsigned int j)
{
	unsigned int		k;

	k = i ^ j;
	printf("XOR operator (^):\n");	
	print_res(i, j, k);
}

void		comp_opp(unsigned int i)
{
	unsigned int		k;

	k = ~i;
	printf("Complement operator (~):\n");	
	print_bits(sizeof(i), &i);
	print_bits(sizeof(k), &k);

}

void		shift_left_opp(unsigned int i, unsigned int j)
{
	unsigned int		k;

	k = i << j;
	printf("Shift left operator (<<):\n");	
	print_bits(sizeof(i), &i);
	print_bits(sizeof(k), &k);

}

void		shift_right_opp(unsigned int i, unsigned int j)
{
	unsigned int		k;

	k = i >> j;
	printf("Shift right operator (>>):\n");	
	print_bits(sizeof(i), &i);
	print_bits(sizeof(k), &k);

}

void		put_bit_one(unsigned int i, unsigned int pos)
{
	unsigned int mask;
	unsigned int res;

	printf("Give value 1 to bit in position %u:\n", pos);	
	mask = 1;
	mask <<= pos;
	res = i | mask;
	print_bits(sizeof(i), &i);
	print_bits(sizeof(mask), &mask);
	print_bits(sizeof(res), &res);
}

void		put_bit_zero(unsigned int i, unsigned int pos)
{
	unsigned int mask;
	unsigned int res;

	printf("Give value 0 to bit in position %u:\n", pos);	
	mask = 1;
	mask <<= pos;
	mask = ~mask;
	res = i & mask;
	print_bits(sizeof(i), &i);
	print_bits(sizeof(mask), &mask);
	print_bits(sizeof(res), &res);
}


int			main(int argc, char** argv)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	*tab;

	(void)argc;
	(void)argv;
	i = 6;
	j = 10;
	and_opp(i, j);
	printf("\n");
	or_opp(i, j);
	printf("\n");
	xor_opp(i, j);
	printf("\n");
	comp_opp(0);
	printf("\n");
	shift_left_opp(258000, 2);
	printf("\n");
	shift_right_opp(258000, 2);
	printf("\n");
	put_bit_one(0, 10);
	printf("\n");
	put_bit_zero(~0, 10);
	printf("\n");
	tab = (unsigned int*)ft_memalloc(32);
	tab[7] = ~0;
	print_bits(32, tab);
	ft_memdel((void **)&tab);
	return (0);
}
