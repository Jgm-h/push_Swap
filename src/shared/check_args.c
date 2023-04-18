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

void	check_duplicates(t_module *node)
{
	int			tmp;
	t_module	*comparing;

	while (node->next)
	{
		tmp = node->data;
		comparing = node->next;
		while (1)
		{
			if (comparing->data == tmp)
				push_swap_error();
			if (comparing->next)
				comparing = comparing->next;
			else
				break ;
		}
		node = node->next;
	}
	while (node->previous)
		node = node->previous;
}

int	is_sorted(t_stack	*stack_a)
{
	t_module	*node;

	node = stack_a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->data > node->next->data)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->data == stack_a->bottom->data)
		return (1);
	else
		return (0);
}
