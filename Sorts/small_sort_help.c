/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:50:10 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/28 23:50:17 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	case1(t_args *args)
{
	swap(&args->a);
	bench_write("sa", &args->benchmark.sa);
}

void	case2(t_args *args)
{
	swap(&args->a);
	bench_write("sa", &args->benchmark.sa);
	reverse_rotate(&args->a);
	bench_write("rra", &args->benchmark.rra);
}

void	case3(t_args *args)
{
	swap(&args->a);
	bench_write("sa", &args->benchmark.sa);
	rotate(&args->a);
	bench_write("ra", &args->benchmark.ra);
}

void	case4(t_args *args)
{
	reverse_rotate(&args->a);
	bench_write("rra", &args->benchmark.rra);
}

void	case5(t_args *args)
{
	rotate(&args->a);
	bench_write("ra", &args->benchmark.ra);
}
