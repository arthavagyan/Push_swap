/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:59:21 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/15 13:24:03 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack -> size < 2)
		return ;
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
}

void	push(t_stack *src_stack, t_stack *dst_stack)
{
	t_node	*node;

	if (!src_stack || !dst_stack || !(src_stack->head))
		return ;
	node = src_stack->head;
	src_stack->head = src_stack->head->next;
	node->next = dst_stack->head;
	dst_stack->head = node;
	src_stack->size--;
	dst_stack->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	last = stack->head;
	while (last->next != NULL)
		last = last->next;
	stack->head = first->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*prev;

	if (!stack || stack->size < 2)
		return ;
	prev = stack->head;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack->head;
	stack->head = last;
}
