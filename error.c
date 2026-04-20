/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:02:36 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/11 20:02:46 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Error codes

|0| -> nothing to free just exit
|1| -> frees double pointer
|2| -> frees list
|3| -> frees list and double pointer
*/
#include "push_swap.h"

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_list(t_node *head)
{
	t_node	*current;
	t_node	*next_node;

	current = head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

void	error_exit(int i, t_args *args)
{
	if (i == 1)
		free_double_pointer(args->args_str);
	if (i == 2)
		free_list(args->a.head);
	if (i == 3)
	{
		free_double_pointer(args->args_str);
		free_list(args->a.head);
	}
	write(2, "Error\n", 6);
	exit(1);
}
