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
#include "../push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->index = -1;
	return (new_node);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

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
	ft_lstadd_back(&stack->head, new);
	stack->size++;
}
