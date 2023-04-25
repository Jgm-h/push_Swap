#include "push_swap.h"

void	free_everything(t_stack *stack_a, t_stack *stack_b)
{
	t_module	*tmp;
	
	while (stack_a->top)
	{
		tmp = stack_a->top;
		stack_a->top = stack_a->top->next;
		free (tmp);
		if (stack_a->top == stack_a->bottom)
		{
			free(stack_a->top);
			break ;
		}
	}
	free (stack_a);
	while (stack_b->top)
	{
		tmp = stack_b->top;
		stack_b->top = stack_b->top->next;
		free(tmp);
		if (stack_b->top == stack_b->bottom)
		{
			free(stack_b->top);
			break ;
		}
	}
	free (stack_b);
}

void	cmd_pa(t_stack *a, t_stack *b)
{
	t_module	*tmp;

	ft_printf("%s", "pa\n");
	tmp = init_node();
	tmp->data = b->top->data;
	relink(b, a, tmp);
}

void	cmd_pb(t_stack *a, t_stack *b)
{
	t_module	*tmp;

	ft_printf("%s", "pb\n");
	tmp = init_node();
	tmp->data = a->top->data;
	relink(a, b, tmp);
}

void	relink(t_stack *from, t_stack *to, t_module *tmp)
{
	if (!to->top)
	{
		to->top = tmp;
		to->bottom = tmp;
	}
	else
	{
		to->top->previous = tmp;
		tmp->next = to->top;
		to->top = to->top->previous;
	}
	tmp = from->top;
	from->top = from->top->next;
	free(tmp);
	to->size++;
	from->size--;
}
