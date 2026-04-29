/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_fill_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 04:38:51 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/29 04:38:56 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	zero_fill_benchmark(t_args *args)
{
	args->benchmark.sa = 0;
	args->benchmark.sb = 0;
	args->benchmark.ss = 0;
	args->benchmark.pa = 0;
	args->benchmark.pb = 0;
	args->benchmark.ra = 0;
	args->benchmark.rb = 0;
	args->benchmark.rr = 0;
	args->benchmark.rra = 0;
	args->benchmark.rrb = 0;
	args->benchmark.rrr = 0;
}

void	zero_fill_struct(t_args *args)
{
	args->a.head = NULL;
	args->a.size = 0;
	args->b.head = NULL;
	args->b.size = 0;
	args->simple = 0;
	args->medium = 0;
	args->complex = 0;
	args->adaptive = 1;
	args->bench = 0;
	zero_fill_benchmark(args);
}
