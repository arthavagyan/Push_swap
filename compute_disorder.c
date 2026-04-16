/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:23:49 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/15 13:08:02 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = stack->head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			total_pairs++;
			if (current->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}
