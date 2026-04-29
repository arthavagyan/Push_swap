/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:57:23 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/15 13:07:12 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

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
