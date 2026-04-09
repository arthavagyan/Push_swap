/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:27:56 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/09 20:53:16 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

typedef struct a_data
{
	int		argc;
	char	**argv;
}		t_arg;

void	parsing(t_arg *args);

size_t	ft_strlcpy(char dst[], const char src[], size_t size);

char	**ft_split(char const *s, char c);
#endif
