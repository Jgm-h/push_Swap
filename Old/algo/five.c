#include "push_swap.h"

void	five(t_stack *stack)
{
	int			count;
	t_module	*current;

	current = stack->top;
	count = 0;
	while (!count)
	{
		if (current != stack->bottom && current->data > current->next->data)
			swap(current);
		else if (current == stack->bottom
			&& current->data < current->next->data)
			swap(current);
		else
		{
			ft_printf("%s", "ra\n");
			current = current->next;
		}
		stack->bottom = stack->top->previous;
		count = is_sorted(stack->top);
	}
}

void	swap(t_module *current)
{
	int	tmp;

	ft_printf("%s\n", "sa");
	tmp = current->data;
	current->data = current->next->data;
	current->next->data = tmp;
}
