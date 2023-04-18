#include "push_swap.h"

int	special_atoi(char *tab)
{
	long	num;
	long	sign;
	int		i;

	if (!check_args(tab))
		push_swap_error();
	i = 0;
	sign = 1;
	num = 0;
	if (tab[i] == ' ')
		tab[i]++;
	if (tab[i] == '-')
		sign = -1;
	if (tab[i] == '-' || tab[i] == '+')
		i++;
	while (tab[i])
		num = (num * 10) + (tab[i++] - 48);
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		push_swap_error();
	return ((int) num);
}
