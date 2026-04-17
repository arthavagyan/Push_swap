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

static int	ischar(char *str, t_args *args)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] && str[i + 1] == '-')
			return (activate_flags(str, args));
		i++;
	}
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static void	check_args_push(t_args *args)
{
	int	i;
	int	nb;

	i = 0;
	while (args->args_str[i])
	{
		if (ischar(args->args_str[i], args) == 1)
			error_exit(1, args);
		else if (ischar(args->args_str[i], args) == 0)
		{
			nb = ft_atoi(args->args_str[i]);
			if (nb == 2147483647)
				error_exit(1, args);
			if (duplicate_numbers(&args->a, nb))
				error_exit(2, args);
			push_stack(&args->a, nb);
		}
		i++;
	}
	free_double_pointer(args->args_str);
}

static void	arr_len_counter(t_args *args)
{
	int	i;
	int	j;
	int len;

	args->total_arr_len = 0;
	i = 1;
	while (i < args->argc)
	{
		j = 0;
		while (args->argv[i][j])
		{
			while (args->argv[i][j] == ' ')
				j++;
			if (args->argv[i][j])
				args->total_arr_len++;
			while (args->argv[i][j] && args->argv[i][j] != ' ')
				j++;
		}
		i++;
	}
}

static void	fill_args(t_args *args)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 1;
	k = 0;
	while (i < args->argc)
	{
		tmp = ft_split(args->argv[i], ' ');
		if (!tmp)
			error_exit(1, args);
		j = 0;
		while (tmp[j])
		{
			args->args_str[k] = ft_strdup(tmp[j]);
			if (!args->args_str[k])
				error_exit(1, args);
			j++;
			k++;
		}
		free_double_pointer(tmp);
		i++;
	}
}

void	parsing(t_args *args)
{
	int	i;

	i = 0;
	arr_len_counter(args);
	if (args->total_arr_len == 0)
		error_exit(0, args);
	args->args_str = ft_calloc(args->total_arr_len + 1, 8);
	if (!(args->args_str))
		error_exit(0, args);
	fill_args(args);
	check_args_push(args);
}
// int	main(int argc, char *argv[])
// {
// 	t_args	args;

// 	args.argc = argc;
// 	args.argv = argv;
// 	if (args.argc < 2)
// 		return (0);
// 	parsing(&args);
// }
/*
static size_t	ft_arrlen(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	zero_fill_struct(t_arg *args)
{
	args->split_tmp = NULL;
	args->new_str = NULL;
	args->old_str = NULL;
}

static void	split_all_args(t_arg *args)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < args->argc)
	{
		args->split_tmp = ft_split(args->argv[i], ' ');
		args->new_str = ft_calloc(ft_arrlen(args->split_tmp)
				+ ft_arrlen(args->old_str) + 1, 1);
		
 		// j = 0;
		// while (args->split_tmp[j])
		// {
		// 	printf("%s\n", args->split_tmp[j]);
		// 	j++;
		// }
		printf("%ld\n", ft_arrlen(args->split_tmp));
		i++;
	}
}

void	parsing(t_arg *args)
{
	zero_fill_struct(args);
	split_all_args(args);
}

int	main(int argc, char *argv[])
{
	t_arg	args;

	args.argc = argc;
	args.argv = argv;
	if (args.argc < 2)
		return (0);
	parsing(&args);
}
*/
/*
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
*/
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
