/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 03:47:28 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/29 04:38:04 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	printflags(t_args *args)
{
	printf("simple:%d\ncomplex:%d\nmedium:%d\nbench:%d\n"
		"adaptive:%d\ndisorder:%f\nsize:%d\n", args->simple,
		args->complex, args->medium, args->adaptive,
		args->bench, args->disorder, args->a.size);
}

void	print_result(t_args *args, int i)
{
	t_node	*old_head;

	old_head = args->a.head;
	if (!i)
	{
		printflags(args);
		while (args->a.head)
		{
			printf("|before sort:|%d\t|index:|%d\n",
				args->a.head->value, args->a.head->index);
			args->a.head = args->a.head->next;
		}
		args->a.head = old_head;
	}
	else if (i)
	{
		while (args->a.head)
		{
			printf("|after sort:|%d\t|index:|%d\n",
				args->a.head->value, args->a.head->index);
			args->a.head = args->a.head->next;
		}
		args->a.head = old_head;
	}
}
