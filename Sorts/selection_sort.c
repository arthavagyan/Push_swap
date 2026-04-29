/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:23:49 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/19 15:24:01 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	find_min_index(t_node *head)
{
	int		min_number_index;
	int		min_number;
	int		current_index;
	t_node	*before_head;

	before_head = head;
	current_index = 0;
	min_number_index = 0;
	min_number = head->value;
	while (head)
	{
		if (head->value < min_number)
		{
			min_number = head->value;
			min_number_index = current_index;
		}
		current_index++;
		head = head->next;
	}
	head = before_head;
	return (min_number_index);
}

void	find_operation(int min_index, t_args *args)
{
	int	i;

	if (min_index <= args->a.size / 2)
	{
		i = 0;
		while (i < min_index)
		{
			rotate(&args->a);
			bench_or_write("ra", &args->benchmark.ra, args->bench);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (args->a.size - min_index))
		{
			reverse_rotate(&args->a);
			bench_or_write("rra", &args->benchmark.rra, args->bench);
			i++;
		}
	}
}

void	selection(t_args *args)
{
	int	min_index;

	args->simple = 1;
	select_small_sort(args);
	if (!is_sorted(&args->a))
	{
		while (args->a.size > 0)
		{
			min_index = find_min_index(args->a.head);
			find_operation(min_index, args);
			push(&args->a, &args->b);
			bench_or_write("pb", &args->benchmark.pb, args->bench);
		}
		while (args->b.size > 0)
		{
			push(&args->b, &args->a);
			bench_or_write("pa", &args->benchmark.pa, args->bench);
		}
	}
}
