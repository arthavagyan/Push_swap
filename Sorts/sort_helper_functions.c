/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 04:30:19 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/29 04:30:40 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	assign_index(t_node *head)
{
	int		min_number_index;
	t_node	*tmp;
	t_node	*current_head;
	t_node	*min_node;

	min_number_index = 0;
	current_head = head;
	while (current_head)
	{
		tmp = head;
		min_node = NULL;
		while (tmp)
		{
			if (tmp->index == -1 && !min_node)
				min_node = tmp;
			else if (tmp->index == -1 && tmp->value < min_node->value)
				min_node = tmp;
			tmp = tmp->next;
		}
		min_node->index = min_number_index;
		min_number_index++;
		current_head = current_head->next;
	}
}

void	bench_write(char *str, int *operation)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	(*operation)++;
}

void	choice_sort(t_args *args)
{
	if (args->complex + args->medium + args->simple + args->adaptive >= 2)
	{
		args->simple = 0;
		args->medium = 0;
		args->complex = 0;
		args->adaptive = 1;
	}
	if (args->adaptive)
	{
		if (args->disorder < 0.2)
			selection(args);
		else if (args->disorder >= 0.2 && args->disorder < 0.5)
			chunk_sort(args);
		else
			radix_sort(args);
	}
	else if (args->simple)
		selection(args);
	else if (args->medium)
		chunk_sort(args);
	else if (args->complex)
		radix_sort(args);
}

void	select_small_sort(t_args *args)
{
	if (args->a.size == 2)
		sort_2(args);
	else if (args->a.size == 3)
		sort_3(args);
	else if (args->a.size == 4 || args->a.size == 5)
		sort_4_5(args);
}
