/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:08:53 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/15 13:12:20 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_arg	args;

	args.argc = argc;
	args.argv = argv;
	if (args.argc < 2)
		return (0);
	parsing(&args);
}

static size_t	ft_arrlen(char **s)
{
	size_t	i;

	i = 0;
	while (s[i][0])
		i++;
	return (i);
}

static void	split_all_args(t_arg *args)
{
	int	i;
	int	j;
	int k;

	i = 2;
	j = 0;
	k = 0;
	while (i < args->argc)
	{
		args->split_tmp = ft_split(args->argv[i], ' ');
		if (!args->split_tmp)
			free_split(args);
				while (args->args_str[i])
	{
		printf("%s\n", args->args_str[i]);
		i++;
	}
		args->args_str = ft_calloc(ft_arrlen(args->old_str)
				+ ft_arrlen(args->split_tmp) + 1, 1);
		while (args->old_str[k])
		{
			args->args_str[j] = args->old_str[k];
			j++;
			k++;
		}
		while (args->split_tmp[k])
		{
			args->args_str[j] = args->split_tmp[k];
			j++;
			k++;
		}
		i++;
	}
}

static void	zero_fill_struct(t_arg *args)
{
	args->args_str = NULL;
	args->old_str = NULL;
}

void	parsing(t_arg *args)
{
	int	i;

	i = 0;
	zero_fill_struct(args);
	split_all_args(args);
	while (args->args_str[i])
	{
		printf("%s\n", args->args_str[i]);
		i++;
	}
}

/*
void	parsing(t_arg	*args, t_stack	*stack)
{
	int		j;
	int		i;
	long	nb;

	i = 1;
	while (i < args->argc)
	{
		j = 0;
		args->split_tmp = ft_split(args->argv[i], ' ');
		while (args->split_tmp[j])
		{
			if (ischar(args->split_tmp[j]))
				error_split(args);
			else
			{
				nb = ft_atoi(args->split_tmp[j]);
				if (nb == 2147483647)
					error_split(args);
				if (duplicate_numbers(stack, (int)nb))
					error_split(args);
				else
					push_stack(stack, nb);
			}
			j++;
		}
		i++;
		free_split(args);
	}
}
*/
