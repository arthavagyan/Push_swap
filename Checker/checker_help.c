#include "../push_swap.h"

static void	do_rr(t_args *args)
{
	rotate(&args->a);
	rotate(&args->b);	
}

static void	do_rrr(t_args *args)
{
	reverse_rotate(&args->a);
	reverse_rotate(&args->b);
}

static void do_ss(t_args *args)
{
		swap(&args->a);
		swap(&args->b);
}

static void error_exit_checker(char *line, t_args *args)
{
	free(line);
	free_list(args->a.head);
	free_list(args->b.head);
	write(2,"Error\n",6);
	exit(1);
}

void	execute_command(char *line, t_args *args)
{
	if (!(ft_strncmp(line, "sa\n", 4)))
			swap(&args->a);
	else if (!(ft_strncmp(line, "sb\n", 4)))
			swap(&args->b);
	else if (!(ft_strncmp(line, "ss\n", 4)))
		do_ss(args);
	else if (!(ft_strncmp(line, "pa\n", 4)))
		push(&args->b,&args->a);
	else if (!(ft_strncmp(line, "pb\n", 4)))
		push(&args->a,&args->b);
	else if (!(ft_strncmp(line, "ra\n", 4))) 
		rotate(&args->a);
	else if (!(ft_strncmp(line, "rb\n", 4))) 
		rotate(&args->b);
	else if (!(ft_strncmp(line, "rr\n", 4))) 
		do_rr(args);
	else if (!(ft_strncmp(line, "rra\n", 5))) 
		reverse_rotate(&args->a);
	else if (!(ft_strncmp(line, "rrb\n", 5))) 
		reverse_rotate(&args->b);
	else if (!(ft_strncmp(line, "rrr\n", 5)))
		do_rrr(args);
	else
			error_exit_checker(line, args);
}