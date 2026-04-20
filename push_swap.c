/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:56:46 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/19 19:32:52 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	choice_sort(t_args *args)
{
	if (args->complex = args->medium || args->simple == args->medium
		|| args->simple == args->complex)
	{
		args->simple = 0;
		args->medium = 0;
		args->complex = 0;
		args->adaptive = 1;
	}
	if (args->adaptive)
	{
		if (args->disorder < 0.2)
			selection(&args->a, &args->b);
		else if (args->disorder >= 0.2 && args->disorder < 0.5)
			chunk_sort(&args->a, &args->b);
		else
			radix_sort(&args->a, &args->b);
	}
	else if (args->simple)
		selection(&args->a, &args->b);
	else if (args->medium)
		chunk_sort(&args->a, &args->b);
	else if (args->complex)
		radix_sort(&args->a, &args->b);
}

int	main(int argc, char *argv[])
{
	t_node	*old_head;
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	zero_fill_struct(&args);
	if (args.argc < 2)
		return (0);
	parsing(&args);
	check_args_push(&args);
	args.disorder = compute_disorder(&args.a);
	//-----Print Flags, disorder, size, before sort list----------
	printf("simple:%d\n", args.simple);
	printf("complex:%d\n", args.complex);
	printf("medium:%d\n", args.medium);
	printf("bench:%d\n", args.bench);
	printf("adaptive:%d\n", args.adaptive);
	printf("disorder:%f\n", args.disorder);
	printf("size:%d\n", args.a.size);
	old_head = args.a.head;
	while (args.a.head)
	{
		printf("|before sort:|%d\n", args.a.head->value);
		args.a.head = args.a.head->next;
	}
	args.a.head = old_head;
	//------------------------------------------------------
	choice_sort(&args);
	//----------------Print after sort list--------------
	printf("simple:%d\n", args.simple);
	printf("complex:%d\n", args.complex);
	printf("medium:%d\n", args.medium);
	printf("bench:%d\n", args.bench);
	printf("adaptive:%d\n", args.adaptive);
	printf("disorder:%f\n", args.disorder);
	printf("size:%d\n", args.a.size);
	old_head = args.a.head;
	while (args.a.head)
	{
		printf("|after sort:|%d\n", args.a.head->value);
		args.a.head = args.a.head->next;
	}
	args.a.head = old_head;
	//--------------------------------------------------
	free_list(args.a.head);
}