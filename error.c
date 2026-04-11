/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:08:53 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/09 22:52:13 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	error_split(t_arg *args)
{
	free_split(args);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(t_arg *args)
{
	int	i;

	i = 0;
	while (args->split_tmp[i])
	{
		free(args->split_tmp[i]);
		i++;
	}
	free(args->split_tmp);
}
