#include "push_swap.h"

void    hundred(t_stack *a, t_stack *b)
{
    int med;

    med = median(a);
    b = push_b(a, b, med);
    push_a(a, b);
    b = second_push_b(a, med);
    push_a(a, b);
}

t_stack *push_b(t_stack *a, t_stack *b, int med)
{
    while (check(a, med))
    {
        if(rot_or_revrot(a, med))
            b->top = rot(a);
        else
            b->top = revrot(a);
    }
    return (b);
}

t_module	*rot(t_stack *a)
{
	while (a->top->data >= med)
	{
		a->top = a->top->next;
		printf("%s",)
	}

}

int rot_or_revrot(t_stack *a, int med)
{
    int         rot;
    int         rev;

    rot = 0;
    rev = 0;
	if (a->top->data <= med)
		return(0);
    while (a->top->data >= med)
    {
		a->top = a->top->next;
		rot++;
	}
	while (a->bottom->data >= med)
	{
		a->bottom = a->bottom->previous;
		rev++;
	}
	if (rev < rot)
		return (1);
	return (0);
}

int check(t_stack *a, int med)
{
    t_module    *current;

    current = a->top;
    while(current != a->bottom)
    {
        if (current->data < med)
            return 1;
        current = current->next;
    }
    return (0);
}
/*
void test(void)
{
        (void) b;
    while(a->top->next)
        a->top = a->top->next;
    while(a->top)
        {
            printf("%d\n", a->top->data);
            a->top = a->top->previous;
        }
}
*/