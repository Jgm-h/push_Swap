#include "push_swap.h"

void	five(t_stack *stack)
{
	int			count;
	t_module	*current;

	current = stack->top;
	count = 0;
	while(!count)
	{
		if (current->next && current->data > current->next->data)
			swap(stack, current);
		else if (!current->next && current->data < stack->top->data)
			swap(stack, current);
		else
		{
			ft_printf("%s", "ra\n");
			if (current->next)
				current = current->next;
			else
				current = stack->top;	
		}
		count = is_sorted(stack->top, stack->bottom);
	}
}

t_module	*compare(t_stack *stack, t_module *current)
{
	int	i;

	i = 0;
	while (1)
	{
		while (current->next && current->data < current->next->data)
		{
			ft_printf("%s\n", "ra");
			current = current->next;
			i++;
		}
		if (!current->next)
		{
			if (current->data > stack->top->data)
			{
				ft_printf("%s\n", "ra");
				current = stack->top;
				i++;
			}
			else
				return (current);
		}
		if (i >= stack->size || current->data > current->next->data)
			return (current);
	}
}

void	swap(t_stack *stack, t_module *current)
{
	int	tmp;

	ft_printf("%s\n", "sa");
	if (current->next)
	{
		tmp = current->data;
		current->data = current->next->data;
		current->next->data = tmp;
	}
	else
	{
		tmp = current->data;
		current->data = stack->top->data;
		stack->top->data = tmp;
	}
}
