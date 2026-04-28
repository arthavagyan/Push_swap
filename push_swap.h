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

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}		t_node;

typedef struct l_list
{
	t_node	*head;
	int		size;
}		t_stack;

typedef struct b_list
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_bench;

typedef struct m_data
{
	int		argc;
	int		total_arr_len;
	int		simple;
	int		adaptive;
	int		complex;
	int		bench;
	int		medium;
	char	**argv;
	char	**args_str;
	t_stack	a;
	t_stack	b;
	t_bench	benchmark;
	double	disorder;
}		t_args;

void	bench_or_write(char *str, int *operation, int bench);
void	push(t_stack *src_stack, t_stack *dst_stack);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	*ft_calloc(size_t nmemb, size_t size);
void	push_stack(t_stack *stack, int value);
void	radix_sort(t_stack *a, t_stack *b);
void	chunk_sort(t_stack *a, t_stack *b);
void	error_exit(int i, t_args *args);
void	free_double_pointer(char **str);
void	reverse_rotate(t_stack *stack);
void	zero_fill_struct(t_args *args);
void	check_args_push(t_args *args);
void	print_bench(t_args *args);
void	selection(t_args *args);
void	free_list(t_node *head);
void	rotate(t_stack *stack);
void	parsing(t_args *args);
void	swap(t_stack *stack);
void	sort_2(t_args *args);
void	sort_3(t_args *args);
void	sort_4_5(t_args *args);
void	find_operation(int min_index, t_args *args);
void	case1(t_args *args);
void	case2(t_args *args);
void	case3(t_args *args);
void	case4(t_args *args);
void	case5(t_args *args);
void	radix(t_args *args);

size_t	ft_strlcpy(char dst[], const char src[], size_t size);
size_t	ft_strlen(const char *s);

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

t_node	*ft_lstnew(int value);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		duplicate_numbers(t_stack *stack, int value);
int		activate_flags(char *str, t_args *args);
int		is_sorted(t_stack *stack);
int		ft_atoi(const char *str);
int		find_min_index(t_node *head);

double	compute_disorder(t_stack *stack);
#endif
