/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:53:33 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/21 15:48:00 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	from_a_to_b_utils(t_args *args, int *mid, int *i, int *range)
{
	if (args->a.head->index <= *i)
	{
		push(&args->a, &args->b);
		bench_write("pb", &args->benchmark.pa, args->bench);
		rotate(&args->b);
		bench_write("rb", &args->benchmark.rb, args->bench);
		(*i)++;
	}
	else if (args->a.head->index <= *i + *range)
	{
		push(&args->a, &args->b);
		bench_write("pb", &args->benchmark.pa, args->bench);
		if (args->b.head->index <= *mid)
		{
			rotate(&args->b);
			bench_write("rb", &args->benchmark.rb, args->bench);
		}
		(*i)++;
	}
	else
	{
		rotate(&args->a);
		bench_write("ra", &args->benchmark.ra, args->bench);
	}
}

static int	find_max_index(t_node *head)
{
	int		max_number_index;
	int		max_number;
	int		current_index;
	t_node	*before_head;

	before_head = head;
	current_index = 0;
	max_number_index = 0;
	max_number = head->value;
	while (head)
	{
		if (head->value > max_number)
		{
			max_number = head->value;
			max_number_index = current_index;
		}
		current_index++;
		head = head->next;
	}
	head = before_head;
	return (max_number_index);
}

static void	from_a_to_b(t_args *args, int range)
{
	int	mid;
	int	i;

	i = 0;
	while (args->a.head)
	{
		mid = i + range / 2;
		from_a_to_b_utils(args, &mid, &i, &range);
	}
}

static void	max_to_top(t_args *args, int max_pos)
{
	int	i;

	i = 0;
	if (max_pos <= args->b.size / 2)
	{
		while (i < max_pos)
		{
			rotate(&args->b);
			bench_write("rb", &args->benchmark.rb, args->bench);
			i++;
		}
	}
	else
	{
		while (i < (args->b.size - max_pos))
		{
			reverse_rotate(&args->b);
			bench_write("rrb", &args->benchmark.rrb, args->bench);
			i++;
		}
	}
}

void	chunk_sort(t_args *args)
{
	int		range;
	int		max_pos;
	int		i;

	args->medium = 1;
	select_small_sort(args);
	if (!is_sorted(&args->a))
	{
		i = 1;
		while (i * i < args->a.size)
			i++;
		i = (i - 1) / 2;
		if (i < 5)
			i = 5;
		range = args->a.size / i;
		from_a_to_b(args, range);
		while (args->b.head)
		{
			max_pos = find_max_index(args->b.head);
			max_to_top(args, max_pos);
			push(&args->b, &args->a);
			bench_write("pa", &args->benchmark.pa, args->bench);
		}
	}
}
