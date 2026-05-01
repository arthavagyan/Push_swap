/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:02:45 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/21 21:16:23 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	ft_putnbr(int n)
{
	long	number;
	int		m;

	number = n;
	if (number > 9)
	{
		ft_putnbr(number / 10);
		m = (number % 10) + '0';
		write(2, &m, 1);
	}
	else
	{
		m = (number % 10) + '0';
		write(2, &m, 1);
	}
}

static void	print_disorder(double disorder)
{
	int	int_part;
	int	frac_part;

	write(2, "[bench] disorder:\t", 19);
	disorder = disorder * 100;
	int_part = (int)disorder;
	frac_part = (int)((disorder - int_part) * 100);
	ft_putnbr(int_part);
	write(2, ".", 1);
	if (frac_part < 10)
		write(2, "0", 1);
	ft_putnbr(frac_part);
	write(2, "%", 1);
	write(2, "\n", 1);
}

static void	total_ops(t_args *args)
{
	long	total_ops;

	total_ops = 0;
	write(2, "[bench] total_ops:\t", 20);
	total_ops = args->benchmark.pa + args->benchmark.pb
		+ args->benchmark.sa + args->benchmark.sb + args->benchmark.ss
		+ args->benchmark.ra + args->benchmark.rb + args->benchmark.rr
		+ args->benchmark.rra + args->benchmark.rrb + args->benchmark.rrr;
	ft_putnbr(total_ops);
	write(2, "\n", 1);
}

static void	print_ops_count(t_args *args)
{
	write(2, "[bench] sa:\t", 13);
	ft_putnbr(args->benchmark.sa);
	write(2, "\tsb:\t", 6);
	ft_putnbr(args->benchmark.sb);
	write(2, "\tss:\t", 6);
	ft_putnbr(args->benchmark.ss);
	write(2, "\tpa:\t", 6);
	ft_putnbr(args->benchmark.pa);
	write(2, "\tpb:\t", 6);
	ft_putnbr(args->benchmark.pb);
	write(2, "\n[bench] ra:\t", 14);
	ft_putnbr(args->benchmark.ra);
	write(2, "\trb:\t", 6);
	ft_putnbr(args->benchmark.rb);
	write(2, "\trr:\t", 6);
	ft_putnbr(args->benchmark.rr);
	write(2, "\trra:\t", 7);
	ft_putnbr(args->benchmark.rra);
	write(2, "\trrb:\t", 7);
	ft_putnbr(args->benchmark.rrb);
	write(2, "\trrr:\t", 7);
	ft_putnbr(args->benchmark.rrr);
	write(2, "\n", 1);
}

void	print_bench(t_args *args)
{
	print_disorder(args->disorder);
	write(2, "[bench] strategy:\t", 19);
	if (args->adaptive)
	{
		write(2, "Adaptive / ", 12);
		if (args->simple)
			write(2, "O(n²)\n", 8);
		else if (args->medium)
			write(2, "O(n√n)\n", 10);
		else
			write(2, "O(nlogn)\n", 10);
	}
	else if (args->simple)
		write(2, "Simple / O(n²)\n", 17);
	else if (args->medium)
		write(2, "Medium / O(n√n)\n", 19);
	else if (args->complex)
		write(2, "Complex / O(nlogn)\n", 20);
	total_ops(args);
	print_ops_count(args);
}
