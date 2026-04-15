/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:27:56 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/15 19:07:00 by artavagy         ###   ########.fr       */
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
	char	**split_tmp;
	char	**old_str;
	char	**args_str;
}		t_arg;
/*
typedef struct s_list
{
	int				value;
	struct s_list	*next;
}		t_node;

typedef struct s_list
{
	t_node	*head;
	int		size;
}		t_stack;
*/

void	error_split(t_arg *args);
void	free_split(t_arg *args);
void	parsing(t_arg *args);
//void	swap(t_stack *stack);
//void	push(t_stack *src_stack, t_stack *dst_stack);
//void	rotate(t_stack *stack);
//void	reverse_rotate(t_stack *stack);
//void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_calloc(size_t nmemb, size_t size);

long	ft_atoi(const char *str);

size_t	ft_strlcpy(char dst[], const char src[], size_t size);
size_t	ft_strlen(const char *s);

char	**ft_split(char const *s, char c);

/*
t_node	*ft_lstnew(void *content);

//int		duplicate_numbers(t_stack *stack, int value);

//double	compute_disorder(t_stack *stack);
*/
#endif
