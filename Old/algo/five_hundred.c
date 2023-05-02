#include "push_swap.h"

void    five_hundred(t_stack *a, t_stack *b)
{
    int medinf;
    int i;

    i = 0;
    median(a);
    while(i <= 3)
    {
        if (i == 0)
            medinf = INT_MIN;
        if (i == 1)
            medinf = a->quartmed;
        if (i == 2)
            medinf = a->med;
        if (i == 3)
            medinf = a->threequartmed;
        push_b_five(a, b, i, medinf);
        push_a(a, b);
        i++;
    }
    while (a->top)
    {
        ft_printf("%d", a->top->data);
        a->top = a->top->next;
    }
    //find(a);

}