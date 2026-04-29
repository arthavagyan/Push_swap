/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:56:46 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/28 23:42:05 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	if (args.argc < 2)
		return (0);
	zero_fill_struct(&args);
	parsing(&args);
	check_args_push(&args);
	compute_disorder(&args);
	assign_index(args.a.head);
	print_result(&args, 0);
	printf("|head value|%d\n", args.a.head->value);
	if (is_sorted(&args.a))
		return (free_list(args.a.head), 0);
	choice_sort(&args);
	if (args.bench)
		print_bench(&args);
	print_result(&args, 1);
	free_list(args.a.head);
	return (0);
}
