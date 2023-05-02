#include "push_swap.h"

void	hundred(t_stack *a, t_stack *b)
{
    median(a);
	push_b(a, b);
	push_a(a, b);
    second_push(a, b);
    push_a(a, b);
    find(a);
    while (a->top->data != a->smallest)
    {
        a->top = a->top->next;
        ft_printf("%s\n", "ra");
        a->bottom = a->top->previous;
    }
}
