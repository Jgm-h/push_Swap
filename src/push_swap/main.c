#include "push_swap.h"

int	main(int argc, char **argv)
{
	long long int	*a;

	a = NULL;
	if (argc > 1)
	{
		a = fill_tab(argc, argv, a);
		check_duplicates(a, argc);
		if (is_sorted(a, argc))
		{
			free(a);
			return (0);
		}
		a = simplify(a, argc);
//		push_swap(a, argc);
	}
	return (0);
}
/*
void	push_swap(int *a, int argc)
{
	if (argc <= 5)
		ici;
	else
		radix(a, argc);
	free(a);
}
*/
void	push_swap_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}
