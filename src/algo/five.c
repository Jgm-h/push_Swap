#include "push_swap.h"

void	five(t_stack *stack)
{
	int			i;
	t_module	*current;

	i = 0;
	current = stack->top;
	while (i < stack->size)
	{
		if (current->data < current->next->data)
		{
			ft_printf("%s\n", "ra");
			current = current->next;
		}
		if (!current->next)
		{
			if (current->data > stack->top->data)
			{
				ft_printf("%s\n", "ra");
				current = stack->top;
			}
		}
		current = compare(stack, current);
		if (current != stack->top)
			swap(stack, current);
	}
	while (stack->top)
	{
		printf("%d\n", stack->top->data);
		stack->top = stack->top->next;
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
