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
	if (b->top == b->top->next)
	{
		tmp->previous = a->bottom;
		a->bottom->next = tmp;
		a->top->previous = tmp;
		tmp->next = a->top;
		a->top = a->top->previous;
		b->top = NULL;
		free(b->top);
		b = NULL;
		free(b);
	}
	else
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

void	relink(t_stack *from, t_stack *to, t_module *tmp) //clean this, still buggy
{
	t_module	*hook;

	if (!to->top)
	{
		to->top = tmp;
		to->top->previous = tmp;
		to->top->next = tmp;
		to->bottom = tmp;
	}
	else
	{
		tmp->previous = to->bottom;
		to->bottom->next = tmp;
		to->top->previous = tmp;
		tmp->next = to->top;
		to->top = to->top->previous;
	}
	hook = from->top;
	from->top = from->top->next;
	from->top->previous = from->top->previous->previous;
	from->top->previous->next = from->top;
	from->bottom = from->top->previous;
	free(hook);
}
