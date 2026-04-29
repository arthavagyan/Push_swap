/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:24:01 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/04/29 19:53:38 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
	t_args  args;

	args.argc = argc;
	args.argv = argv;
	zero_fill_struct(&args);
	parsing(&args);
	read_and_execute(&args);
	check_args_push(&args);
	if (is_sorted(&args.a) && args.b.head == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_list(args.a.head);
	return (0);
}
