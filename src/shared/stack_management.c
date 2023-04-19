#include "push_swap.h"

void	free_everything(t_stack *stack_a, t_stack *stack_b)
{
    t_module    *tmp;
    
    while (stack_a->top)
    {
        tmp = stack_a->top;
        stack_a->top = stack_a->top->next;   
        free (tmp);
    }
    free (stack_a);
    while (stack_b->top)
    {
        tmp = stack_b->top;
        stack_b->top = stack_b->top->next;   
        free(tmp);
    }
    free (stack_b);
}
