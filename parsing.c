/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:08:53 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/09 22:52:13 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ischar(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!str)
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

static long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = (result * 10) + (*str - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (2147483647);
		str++;
	}
	return (result * sign);
}

void	parsing(t_arg	*args)
{
	int	j;
	int	i;
	long	nb;
	char	**tmp;

	i = 1;
	while (i < args->argc)
	{
		j = 0;
		tmp = ft_split(args->argv[i], ' ');
		while (tmp[j])
		{
			if (ischar(tmp[j]))
				return ;//error + free
			else
			{
				nb = ft_atoi(tmp[j]);
				if (nb == 2147483647)
					return ;//error + free
				printf("%ld", nb);
			}
			j++;
		}
		i++;
	}
}
