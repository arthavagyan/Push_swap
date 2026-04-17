/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:56:46 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/15 13:13:11 by tyeghiaz         ###   ########.fr       */
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
	while (args.a.head)
	{
		printf("%d\n", args.a.head->value);
		args.a.head = args.a.head->next;
	}
	printf("simple:%d\n", args.simple);
	printf("complex:%d\n", args.complex);
	printf("medium:%d\n", args.medium);
	printf("bench:%d\n", args.bench);
	printf("adaptive:%d\n", args.adaptive);
	args.disorder = compute_disorder(&args.a);
}
   