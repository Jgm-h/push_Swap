#include "push_swap.h"

int	check_args(char *tab)
{
	int	len;

	len = check_args_length(tab);
	if (!is_numeric(tab) || len > 11 || len < 0)
		return (0);
	else
		return (1);
}

int	check_args_length(char *tab)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (tab[0] == '+' || tab[0] == '-')
	{
		i++;
		len--;
	}
	while (tab[i] == '0')
		i++;
	while (tab[i++])
		len++;
	return (len);
}

int	is_numeric(char *tab)
{
	int	i;

	if (!tab)
		return (0);
	i = -1;
	if (tab[0] == '+' || tab[0] == '-')
		i++;
	while (tab[++i])
	{
		if (!ft_isdigit(tab[i]))
			return (0);
	}
	return (1);
}

void	check_duplicates(long long int *tab, int argc)
{
	int	i;
	int	comparing;

	i = 0;
	while (i < argc - 2)
	{
		if (i == argc - 1)
			break ;
		comparing = i + 1;
		while (comparing < argc - 1)
		{
			if (tab[comparing] == tab[i])
				push_swap_error();
			if (tab[comparing] != tab[i])
				comparing++;
			else
				break ;
		}
		i++;
	}
}

int	is_sorted(long long int *a, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
