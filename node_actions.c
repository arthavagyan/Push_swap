/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:24:02 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/15 13:20:54 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	push_stack(t_stack *stack, int value)
{
	t_node	*new;

	new = ft_lstnew(value);
	if (!new)
		return ;
	ft_lstadd_front(&stack->head, new);
	stack->size++;
}
