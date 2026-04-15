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
	t_arg	args;
	t_stack	a;
	t_stack	b;
	double	disorder;

	args.argc = argc;
	args.argv = argv;
	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (args.argc < 2)
		return (0);
	parsing(&args, &a);
	disorder = compute_disorder(&a);
}
