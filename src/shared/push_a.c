#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	(void) a;
	find(b);
//	if (how_close(b))
//		return ;
//		reverse(b, a, how_close(b));

	/*find how close they are,
	rev or rot,
	push_a*/
}

void	reverse(t_stack *b, t_stack *a, int flag)
{
	b->top->previous = b->bottom;
	b->bottom->next = b->top;
	if (flag < 0)
	{
		while (b->top->data != b->biggest || b->top->data != b->smallest)
		{
			b->top = b->top->previous;
			ft_printf("%s", "rrb\n");
		}
	}
	else
	{
		while (b->top->data != b->biggest || b->top->data != b->smallest)
		{
			b->top = b->top->next;
			ft_printf("%s", "rrb\n");
		}
	}
	b->bottom = b->top->previous;
	b->top->previous->next = NULL;
	b->top->previous = NULL;
	cmd_pa(a, b);
}

void	find(t_stack *b)
{
	t_module	*current;

	current = b->top;
	while (current->next)
	{
		if (current->data < b->smallest)
			b->smallest = current->data;
		if (current->data > b->biggest)
			b->biggest = current->data;
		current = current->next;
	}
}

int	how_close(t_stack *b)
{
	t_module	*current;
	int			rev;
	int			rot;

	rot = 0;
	rev = 1;
	current = b->top;
	while (current->data != b->smallest || current->data != b->biggest)
	{
		current = current->next;
		rot++;
	}
	current = b->bottom;
	while (current->data != b->smallest || current->data != b->biggest)
	{
		current = current->previous;
		rev++;
	}
	if (rev < rot)
		return (-rev);
	else
		return (rot);
}
