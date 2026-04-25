#include "push_swap.h"

void	case1(t_args *args)
{
	swap(&args->a);
	bench_or_write("sa", &args->benchmark.sa, args->bench);
}

void	case2(t_args *args)
{
	swap(&args->a);
	bench_or_write("sa", &args->benchmark.sa, args->bench);
	reverse_rotate(&args->a);
	bench_or_write("rra", &args->benchmark.rra, args->bench);
}

void	case3(t_args *args)
{
	swap(&args->a);
	bench_or_write("sa", &args->benchmark.sa, args->bench);
	rotate(&args->a);
	bench_or_write("ra", &args->benchmark.ra, args->bench);
}

void	case4(t_args *args)
{
	reverse_rotate(&args->a);
	bench_or_write("rra", &args->benchmark.rra, args->bench);
}

void	case5(t_args *args)
{
	rotate(&args->a);
	bench_or_write("ra", &args->benchmark.ra, args->bench);
}
