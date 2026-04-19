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

int	main(int argc, char *argv[])
{
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	zero_fill_struct(&args);
	if (args.argc < 2)
		return (0);
	parsing(&args);
	/*while (args.a.head)
	{
		printf("|before sort:%d\n |", args.a.head->value);
		args.a.head = args.a.head->next;
	}*/
	printf("simple:%d\n", args.simple);
	printf("complex:%d\n", args.complex);
	printf("medium:%d\n", args.medium);
	printf("bench:%d\n", args.bench);
	printf("adaptive:%d\n", args.adaptive);
	args.disorder = compute_disorder(&args.a);
	printf("disorder:%f", args.disorder);
	if (args.adaptive && (args.disorder < 0.2))
		selection(&args.a, &args.b);
	else if (args.simple)
		selection(&args.a, &args.b);
	while (args.a.head)
	{
		printf("|after sort:|%d\n", args.a.head->value);
		args.a.head = args.a.head->next;
	}	
}