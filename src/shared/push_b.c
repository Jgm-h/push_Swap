#include "push_swap.h"

void	push_b(t_stack *a, t_stack *b, int med)
{
	while (check(a, med, 1))
	{
		if (rot_or_revrot(a, med) < 0)
		{
			a->top->previous = a->bottom;
			a->bottom->next = a->top;
			while (a->top->data >= med) //bug here, with the bottom/top situation
			{
				a->top = a->top->next;
				ft_printf("%s", "ra\n");
			}
			cmd_pb(a, b);
			a->bottom = a->top->previous;
			a->top->previous = NULL;
			a->bottom->next = NULL;
		}
		else if (rot_or_revrot(a, med) == 0)
			cmd_pb(a, b);
		else
			rot(a, b, med, 1);
	}
}

void	rot(t_stack *a, t_stack *b, int med, int flag)
{
	a->top->previous = a->bottom;
	a->bottom->next = a->top;
	if (flag)
	{
		while (a->top->data >= med)
		{
			a->top = a->top->previous;
			ft_printf("%s", "rra\n");
		}
	}
	else
	{
		while (a->top->data < med)
		{
			a->top = a->top->previous;
			ft_printf("%s", "rra\n");
		}
	}
	a->bottom = a->top->previous;
	a->top->previous->next = NULL;
	a->top->previous = NULL;
	cmd_pb(a, b);
}

t_stack	*second_push(t_stack *a, t_stack *b, int med)
{
	while (check(a, med, 0))
	{
		if (rot_or_revrot(a, med) < 0)
		{	
			while (a->top->data < med)
			{
				a->top = a->top->next;
				ft_printf("%s", "ra\n");
			}
			cmd_pb(a, b);
		}
		else if (rot_or_revrot(a, med) == 0)
			cmd_pb(a, b);
		else
			rot(a, b, med, 0);
	}
	return (b);
}

int	rot_or_revrot(t_stack *a, int med)
{
	int			rot;
	int			rev;
	t_module	*current;

	current = a->top;
	rot = 0;
	rev = 1;
	if (current->data < med)
		return (0);
	while (current->data >= med && current->next)
	{
		current = current->next;
		rot++;
	}
	current = a->bottom;
	while (current->data >= med && current->previous)
	{
		current = current->previous;
		rev++;
	}
	if (rev < rot)
		return (rev);
	return (-rot);
}

int	check(t_stack *stack, int med, int flag)
{
	t_module	*current;

	current = stack->top;
	if (flag)
	{
		while (current != stack->bottom)
		{
			if (current->data < med)
				return (1);
			current = current->next;
		}
		if (current->data < med)
			return (1);
		return (0);
	}
	while (current != stack->bottom)
	{
		if (current->data >= med)
			return (1);
		current = current->next;
	}
	if (current->data >= med)
		return (1);
	return (0);
}
