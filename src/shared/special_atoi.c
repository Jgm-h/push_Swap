#include "push_swap.h"

long long int	special_atoi(char *tab)
{
	long long int	num;
	long long int	sign;
	int				i;

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
	return (num);
}

long long int	*simplify(long long int *a, int argc)
{
	long long int	*tab;
	int				i;
	int				j;

	i = 0;
	j = 0;
	tab = malloc(sizeof (long long int) * argc - 2);
	while (i < argc - 1)
	{
		tab[i] = a[i];
		i++;
	}
	tab = sort(tab, argc);
	i = -1;
	while (++i < argc - 1)
	{
		while (j < argc - 1)
		{
			if (a[i] == tab[j])
				a[i] = j;
			j++;
		}
		j = 0;
	}
	return (a);
}

long long int	*sort(long long int *tab, int argc)
{
	int				i;
	int				j;
	long long int	temp;

	i = 0;
	j = 0;
	while (i < argc - 2)
	{
		while (j < argc - i - 2)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (tab);
}
