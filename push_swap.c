/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:56:46 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/19 19:32:52 by tyeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void    assign_index(t_node *head)
{
        int     min_number_index;
        t_node  *tmp;
        t_node  *first_head;
        t_node  *min_node;

        first_head = head;
        min_number_index = 0;
        while (head)
        {
				tmp = first_head;
				min_node = NULL;
                while(tmp)
                {
					if (tmp->index == -1)
					{
						if (!min_node)
							min_node = tmp;
						if (tmp->value < min_node->value)
							min_node = tmp;
					}
					tmp = tmp->next;
                }
                min_node->index = min_number_index;
				min_number_index++;
				head = head->next;
        }
        head = first_head;
}

void	bench_or_write(char *str, int *operation, int bench)
{
	int	i;

	i = 0;
	if (!bench)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	(*operation)++;
}

static void	choice_sort(t_args *args)
{
	int	flag_count;

	flag_count = 0;
	if (args->complex + args->medium + args->simple + args->adaptive >= 2)
	{
		args->simple = 0;
		args->medium = 0;
		args->complex = 0;
		args->adaptive = 1;
	}
	if (args->adaptive)
	{
		if (args->disorder < 0.2)
			selection(args);
		else if (args->disorder >= 0.2 && args->disorder < 0.5)
			chunk_sort(&args->a, &args->b);
		else
			radix_sort(&args->a, &args->b);
	}
	else if (args->simple)
		selection(args);
	else if (args->medium)
		chunk_sort(&args->a, &args->b);
	else if (args->complex)
		radix_sort(&args->a, &args->b);
}

int	main(int argc, char *argv[])
{
	//t_node	*old_head;
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	zero_fill_struct(&args);
	if (args.argc < 2)
		return (0);
	parsing(&args);
	check_args_push(&args);
	if (is_sorted(&args.a))
		return (0);
	assign_index(args.a.head);
	if (args.a.size <= 5)
	{
		if (args.a.size == 2)
			sort_2(&args);
		else if (args.a.size == 3)
			sort_3(&args);
		else
			sort_4_5(&args);
	}
	else
	{
		args.disorder = compute_disorder(&args.a);
		choice_sort(&args);
	}
	if (args.bench)
		print_bench(&args);
	free_list(args.a.head);
	return (0);
}

/*
	//-----Print Flags, disorder, size, before sort list----------
	printf("simple:%d\n", args.simple);
	printf("complex:%d\n", args.complex);
	printf("medium:%d\n", args.medium);
	printf("bench:%d\n", args.bench);
	printf("adaptive:%d\n", args.adaptive);
	printf("disorder:%f\n", args.disorder);
	printf("size:%d\n", args.a.size);
	old_head = args.a.head;
	while (args.a.head)
	{
		printf("|before sort:|%d\n", args.a.head->value);
		args.a.head = args.a.head->next;
	}
	args.a.head = old_head;
	//------------------------------------------------------
	choice_sort(&args);
	if (args.bench)
		print_bench(&args);
	//----------------Print after sort list--------------
	printf("simple:%d\n", args.simple);
	printf("complex:%d\n", args.complex);
	printf("medium:%d\n", args.medium);
	printf("bench:%d\n", args.bench);
	printf("adaptive:%d\n", args.adaptive);
	printf("disorder:%f\n", args.disorder);
	printf("size:%d\n", args.a.size);
	old_head = args.a.head;
	while (args.a.head)
	{
		printf("|after sort:|%d\n", args.a.head->value);
		args.a.head = args.a.head->next;
	}
	args.a.head = old_head;
	//--------------------------------------------------
	free_list(args.a.head);
*/
