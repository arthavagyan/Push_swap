/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeghiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:24:01 by tyeghiaz          #+#    #+#             */
/*   Updated: 2026/05/01 00:35:53 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	read_command(t_args *args)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_command(line, args);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	zero_fill_struct(&args);
	parsing(&args);
	check_args_push(&args);
	read_command(&args);
	if (is_sorted(&args.a) && args.b.head == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_list(args.a.head);
	free_list(args.b.head);
	return (0);
}
