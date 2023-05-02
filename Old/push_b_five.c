#include "push_swap.h"

void    push_b_five(t_stack *a, t_stack *b, int flag, int medinf)
{
    int medsupp;

    if (flag == 0)
        medsupp = a->quartmed;
    if (flag == 1)
        medsupp = a->med;
    if (flag == 2)
        medsupp = a->threequartmed;
    if (flag == 3)
        medsupp = INT_MAX;
    while (check_five(a, medsupp, medinf))
    {
        if (rot_or_revrot_five(a, medinf, medsupp) < 0)
        {
            while (a->top->data >= medsupp && a->top->data < medinf)
            {
                a->top = a->top->next;
                ft_printf("%s", "ra\n");
            }
            cmd_pb(a, b);
        }
        else if (rot_or_revrot_five(a, medinf, medsupp) == 0)
            cmd_pb(a, b);
        else
            rot_five(a, b, medsupp, 1);
    }
}

void	rot_five(t_stack *a, t_stack *b, int medinf, int medsupp)
{
    while (a->top->data >= medsupp && a->top->data < medinf)
    {
        a->top = a->top->previous;
        ft_printf("%s", "rra\n");
    }
    cmd_pb(a, b);
}

int	rot_or_revrot_five(t_stack *a, int medinf, int medsupp)
{
    int			rot;
    int			rev;
    t_module	*current;

    current = a->top;
    rot = 0;
    rev = 0;
    if (current->data < medsupp && current->data >= medinf)
        return (0);
    while (current->data >= medsupp && current->data < medinf)
    {
        current = current->next;
        rot++;
    }
    current = a->top;
    while (current->data >= medsupp && current->data < medinf)
    {
        current = current->previous;
        rev++;
    }
    if (rev < rot)
        return (rev);
    return (-rot);
}

int	check_five(t_stack *stack, int medsupp, int medinf)
{
    t_module	*current;

    current = stack->top;
    while (current != stack->bottom)
    {
        if (current->data >= medinf && current->data < medsupp)
            return (1);
        current = current->next;
    }
    if (current->data >= medinf && current->data < medsupp)
        return (1);
    return (0);
}