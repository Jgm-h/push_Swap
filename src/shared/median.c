#include "push_swap.h"

int     median(t_stack *stack)
{
	t_stack *tmp;
//	int		med;

	tmp = init_stack();
	tmp->top = init_node();
	fill_tmp(tmp, stack);
	sort(tmp);
//	med = find_median(tmp);
//	free_median(tmp);
//	printf("%d", med);
	return (0);
}

void	fill_tmp(t_stack *tmp, t_stack *stack)
{
	tmp->size = stack->size;
	tmp->top = init_node();
    while (stack->top != stack->bottom)
    {
        tmp->top->data = stack->top->data;
		tmp->top->next = init_node();
        tmp->top = tmp->top->next;
        stack->top = stack->top->next;
    }
	tmp->bottom = tmp->top;
    return ;
}

void	sort(t_stack *tmp)
{
	int 		count;
	t_module	*current;
	t_module	*top;

	top = tmp->top;
	current = tmp->top;
	count = 0;
	while(!count)
	{
		if (current->next && current->data > current->next->data)
			swap_median(tmp->top, current);
		else if (!current->next && current->data < tmp->top->data)
			swap_median(tmp->top, current);
		else
		{
			if (current->next)
				current = current->next;
			else
				current = tmp->top;	
		}
		count = is_sorted(tmp->top, tmp->bottom);
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

int	find_median(t_stack	*tmp)
{
	int	i;

	i = 0;
	while(i < tmp->size/2)
	{
		tmp->top = tmp->top->next;
		i++;
	}
	return (tmp->top->data);
}

void	free_median(t_stack *tmp)
{
	t_module	*top;

	top = tmp->top;
	while (tmp->top)
	{
		tmp->top = tmp->top->next;
		free(top);
		top = tmp->top;
	}
	free (tmp);
}
