#include "push_swap.h"

void	median(t_stack *stack)
{
	t_stack		*tmp;

	tmp = init_stack();
	tmp->top = fill_tmp(tmp, stack);
	sort(tmp);
	find_median(tmp, stack);
	free_median(tmp);
}

t_module	*fill_tmp(t_stack *tmp, t_stack *stack)
{
	t_module	*current;
	t_module	*stack_top;

	tmp->top = init_node();
	current = tmp->top;
	stack_top = stack->top;
	tmp->size = stack->size;
	while (1)
	{
		tmp->top->data = stack->top->data;
		if (stack->top == stack->bottom)
			break ;
		tmp->top->next = init_node();
		tmp->top = tmp->top->next;
		stack->top = stack->top->next;
	}
	tmp->bottom = tmp->top;
	stack->top = stack_top;
	return (current);
}

void	sort(t_stack *tmp)
{
	int			count;
	t_module	*current;
	t_module	*top;

	top = tmp->top;
	current = tmp->top;
	count = 0;
	while (!count)
	{
		if (current != tmp->bottom && current->data > current->next->data)
			swap_median(tmp->top, current);
		else if (current == tmp->bottom && current->data < tmp->top->data)
			swap_median(tmp->top, current);
		else
		{
			if (current != tmp->bottom)
				current = current->next;
			else
				current = tmp->top;
		}
		count = is_sorted(tmp->top);
	}
	tmp->top = top;
}

void	swap_median(t_module *top, t_module *current)
{
	int	tmp;

	if (current->next)
	{
		tmp = current->data;
		current->data = current->next->data;
		current->next->data = tmp;
	}
	else
	{
		tmp = current->data;
		current->data = top->data;
		top->data = tmp;
	}
}

void	find_median(t_stack	*tmp, t_stack *stack)
{
	int	i;

	i = 0;
    while (i++ < tmp->size)
    {
        tmp->top = tmp->top->next;
        if (i == tmp->size/4)
            stack->quartmed = tmp->top->data;
        if (i == tmp->size/2)
            stack->med = tmp->top->data;
        if (i == tmp->size/4 * 3)
            stack->threequartmed = tmp->top->data;
    }
}

void	free_median(t_stack *tmp)
{
	t_module	*top;

	top = tmp->top;
	while (tmp->top)
	{
		tmp->top = tmp->top->next;
		free(top);
        top = NULL;
		top = tmp->top;
	}
    tmp->bottom = NULL;
	free(tmp);
    tmp = NULL;
}
