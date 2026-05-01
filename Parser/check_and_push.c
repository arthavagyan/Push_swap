/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:43:20 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/29 04:39:21 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	is_flag(char *str, t_args *args)
{
	if (!ft_strncmp(str, "--simple", 9))
	{
		args->simple = 1;
		args->adaptive = 0;
	}
	else if (!ft_strncmp(str, "--medium", 9))
	{
		args->medium = 1;
		args->adaptive = 0;
	}
	else if (!ft_strncmp(str, "--complex", 10))
	{
		args->complex = 1;
		args->adaptive = 0;
	}
	else if (!ft_strncmp(str, "--adaptive", 11))
		args->adaptive = 1;
	else if (!ft_strncmp(str, "--bench", 8))
		args->bench = 1;
	else
		return (1);
	return (2);
}

static int	is_char(char *str, t_args *args)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] && str[i + 1] == '-')
			return (is_flag(str, args));
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

void	check_args_push(t_args *args)
{
	int		i;
	long	nb;

	i = 0;
	while (args->args_str[i])
	{
		if (is_char(args->args_str[i], args) == 1)
			error_exit(3, args);
		else if (is_char(args->args_str[i], args) == 0)
		{
			nb = ft_atoi(args->args_str[i]);
			if (nb == 2147483648)
				error_exit(3, args);
			if (duplicate_numbers(&args->a, (int)nb))
				error_exit(3, args);
			push_stack(&args->a, (int)nb);
		}
		i++;
	}
	free_double_pointer(args->args_str);
}
