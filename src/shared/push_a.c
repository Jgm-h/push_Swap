#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	int	rot_rev_a;


	while (b->top)
	{
		find(b);
		rot_rev_a = how_close(b);
		reverse(b, a, how_close(b));
		if (rot_rev_a < 0)
		{

		}
	}



	//to clean that there is still a stack b->top after trying to push

	/*find how close they are,
	rev or rot,
	push_a
	then rotate a or leave on top*/
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

void	find(t_stack *b)
{
	t_module	*current;

	current = b->top;
	b->smallest = INT_MAX;
	b->biggest = INT_MIN;
	while (current->next)
	{
		if (current->data < b->smallest)
			b->smallest = current->data;
		if (current->data > b->biggest)
			b->biggest = current->data;
		current = current->next;
		if (current == b->top)
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
