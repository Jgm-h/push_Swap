#include "push_swap.h"

long long int	*fill_tab(int argc, char **argv, long long int *tab)
{
	int			i;
	int			j;
	char		**split;

	i = 0;
	j = 0;
	tab = malloc(sizeof(long long int) * argc - 1);
	while (i < argc - 1)
	{
		if (!i)
		{
			split = ft_split(argv[i + 1]);
			if (!split)
				push_swap_error();
			while (split[j])
				tab[i] = special_atoi(split[j++]);
			i++;
		}
		else
		{
			tab[i] = special_atoi(argv[i + 1]);
			i++;
		}
	}
	free(split);
	return (tab);
}
