#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = init_stack();
		a->top = fill_stack(argc, argv, &a);
		check_duplicates(a->top);
		b = init_stack();
/*		if (is_sorted(a))
		{
			free_everything(a, b);
			return (0);
		}*/
		push_swap(a, b);
//		free_everything(a, b);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
	{
		(void) stack_b;
		five(stack_a);
	}

/*	if (stack_a->size <= 100 && stack_a->size > 5)
		hundred(stack_a, stack_b);
	if (stack_a->size <= 500 && stack_a->size > 100)
		five_hundred(stack_a, stack_b);*/
}

void	push_swap_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}
