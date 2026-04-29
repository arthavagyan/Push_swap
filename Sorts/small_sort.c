/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:50:36 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/28 23:51:57 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sort_2(t_args *args)
{
	if (args->a.head->value > args->a.head->next->value)
	{
		swap(&args->a);
		bench_or_write("sa", &args->benchmark.sa, args->bench);
	}
}

void	sort_3(t_args *args)
{
	int	first;
	int	second;
	int	third;

	first = args->a.head->value;
	second = args->a.head->next->value;
	third = args->a.head->next->next->value;
	if (first > second && first < third && second < third)
		case1(args);
	else if (first > second && first > third && second > third)
		case2(args);
	else if (first < second && second > third && first < third)
		case3(args);
	else if (first < second && second > third && first > third)
		case4(args);
	else
		case5(args);
}

void	sort_4_5(t_args *args)
{
	int	min_index;

	while (args->a.size > 3)
	{
		min_index = find_min_index(args->a.head);
		find_operation(min_index, args);
		push(&args->a, &args->b);
		bench_or_write("pb", &args->benchmark.pb, args->bench);
	}
	sort_3(args);
	while (args->b.size > 0)
	{
		push(&args->b, &args->a);
		bench_or_write("pa", &args->benchmark.pa, args->bench);
	}
}
