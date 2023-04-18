#include "push_swap.h"

t_module	*fill_stack(int argc, char **argv, t_stack **stack)
{
	int			i;
	t_module	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
		fill_node(argv[i], &node, stack);
	if (!node->next)
		(*stack)->bottom = node;
	while (node->previous)
		node = node->previous;
	return (node);
}

void	fill_node(char *argv, t_module **node, t_stack **stack)
{
	int			i;
	char		**tab;
	t_module	*tmp;

	i = -1;
	tab = ft_split(argv);
	if (!tab)
		push_swap_error();
	while (tab[++i])
	{
		tmp = init_node();
		tmp->data = special_atoi(tab[i]);
		linking(&tmp, node, stack);
		(*stack)->size++;
		free(tab[i]);
	}
	free(tab);
}

t_module	*init_node(void)
{
	t_module	*node;

	node = malloc(sizeof (t_module));
	if (!node)
		push_swap_error();
	node->data = 0;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	if (!stack)
		push_swap_error();
	stack->size = 0;
	stack->bottom = NULL;
	stack->top = NULL;
	return (stack);
}

void	linking(t_module **tmp, t_module **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *tmp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *tmp;
		(*tmp)->previous = *node;
		*node = (*node)->next;
	}
}
