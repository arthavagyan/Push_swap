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

static void	arr_len_counter(t_args *args)
{
	int	i;
	int	j;
	int	len;

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
}
