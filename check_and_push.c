/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:43:20 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/20 19:43:25 by artavagy         ###   ########.fr       */
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

void	check_args_push(t_args *args)
{
	int	i;
	int	nb;

	i = 0;
	while (args->args_str[i])
	{
		if (ischar(args->args_str[i], args) == 1)
			error_exit(3, args);
		else if (ischar(args->args_str[i], args) == 0)
		{
			nb = ft_atoi(args->args_str[i]);
			if (nb == 2147483647)
				error_exit(3, args);
			if (duplicate_numbers(&args->a, nb))
				error_exit(3, args);
			push_stack(&args->a, nb);
		}
		i++;
	}
	free_double_pointer(args->args_str);
}