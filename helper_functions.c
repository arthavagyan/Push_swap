/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:57:23 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/15 13:07:12 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	duplicate_numbers(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	activate_flags(char *str, t_args *args)
{
	if (!ft_strncmp(str, "--simple", 9))
	{
		args->simple = 1;
		args->adaptive = 0;
	}
	else if (!ft_strncmp(str, "--medium", 9))
	{
		args->medium = 1;
		args->adaptive = 0;
	}
	else if (!ft_strncmp(str, "--complex", 10))
	{
		args->complex = 1;
		args->adaptive = 0;
	}
	else if (!ft_strncmp(str, "--adaptive", 11))
		args->adaptive = 1;
	else if (!ft_strncmp(str, "--bench", 8))
		args->bench = 1;
	else
		return (1);
	return (2);
}

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

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (stack == NULL || stack->size < 2)
		return (1);
	cur = stack->head;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
