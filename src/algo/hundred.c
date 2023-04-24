#include "push_swap.h"

void    hundred(t_stack *a, t_stack *b)
{
    int med;

    med = median(a);
    printf("%d", med);
    push_b(a, b, med);

//    push_a(a, b);
//    b = second_push_b(a, med, 0);
//    push_a(a, b);
}

/*void    push_a(t_stack *a, t_stack *b,)
{
    //look for rev or rot and push to a, if rev/rot push over/under
    int rotations;

    rotations = rot_or_revrot(b, INT_MAX);
    if (!rotations)
        cmd_pb(a, b);
    if (rotations < 0)
    {
        rot
    }
}*/
