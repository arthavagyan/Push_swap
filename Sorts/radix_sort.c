/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:53:45 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/29 02:27:16 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static	int	find_max_index_bits(t_args *args)
{
	int	max_index;
	int	iteration;

	iteration = 0;
	max_index = args->a.size - 1;
	while (max_index != 0)
	{
		max_index = max_index >> 1;
		iteration++;
	}
	return (iteration);
}

static void	find_operation_bit(t_args *args, int bit)
{
	if ((args->a.head->index >> bit) & 1)
	{
		rotate(&args->a);
		bench_or_write("ra", &args->benchmark.ra, args->bench);
	}
	else
	{
		push(&args->a, &args->b);
		bench_or_write("pb", &args->benchmark.pb, args->bench);
	}
}

void	radix_sort(t_args *args)
{
	int	max_bits;
	int	i;
	int	size;
	int	bit;

	select_small_sort(args);
	max_bits = (ft_strlen("\0"), bit = 0, find_max_index_bits(args));
	while (bit < max_bits)
	{
		i = -1;
		size = args->a.size;
		if (is_sorted(&(args->a)))
			break ;
		while (++i < size)
			find_operation_bit(args, bit);
		while (args->b.size)
		{
			push(&args->b, &args->a);
			bench_or_write("pa", &args->benchmark.pa, args->bench);
		}
		bit++;
	}
}
