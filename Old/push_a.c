#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	while (b->top)
	{
		find(b);
		reverse(b, a, how_close(b));
		if (a->top->data == b->smallest)
		{
            ft_printf("%s\n", "rra");
            a->top = a->top->next;
            a->bottom = a->top->previous;
		}
	}
}

void	reverse(t_stack *b, t_stack *a, int flag)
{
	if (flag < 0)
	{
		while (b->top->data != b->biggest && b->top->data != b->smallest)
		{
			b->top = b->top->previous;
			ft_printf("%s", "rrb\n");
		}
	}
	else
	{
		while (b->top->data != b->biggest && b->top->data != b->smallest)
		{
			b->top = b->top->next;
			ft_printf("%s", "rb\n");
		}
	}
	b->bottom = b->top->previous;
	cmd_pa(a, b);
}

void	find(t_stack *stack)
{
	t_module	*current;

	current = stack->top;
	stack->smallest = INT_MAX;
	stack->biggest = INT_MIN;
	while (current->next)
	{
		if (current->data < stack->smallest)
			stack->smallest = current->data;
		if (current->data > stack->biggest)
			stack->biggest = current->data;
		current = current->next;
		if (current == stack->top)
			break ;
	}
}

int	how_close(t_stack *b)
{
	t_module	*current;
	int			rev;
	int			rot;

	rot = 0;
	rev = 0;
	current = b->top;
	while (current->data != b->smallest && current->data != b->biggest)
	{
		current = current->next;
		rot++;
	}
	current = b->top;
	while (current->data != b->smallest && current->data != b->biggest)
	{
		current = current->previous;
		rev++;
	}
	if (rev < rot)
		return (-rev);
	else
		return (rot);
}
