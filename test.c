#include "./libft/includes/libft.h"
#include "stdio.h"

void    call(t_stack *a);

int main(void)
{
	if (0 < 0)
		printf("%d", 1);
	else
		printf("%d", 0);
	/*
    t_stack    *a;
    t_module    *tmp;
    t_module    *top;
    int i;

    a = malloc(sizeof(t_stack));
    tmp = malloc(sizeof(t_module));
    i = 0;
    top = tmp;
    while (i < 9)
    {
        tmp->data = i++;
        printf("%d", tmp->data);
        tmp->next = malloc(sizeof(t_module));
        tmp = tmp->next;
    }
    a->top = top;
    printf("\n%d", a->top->data);
    call(a);
    printf("\n%d", a->top->data);*/
    return 0 ;
}

void	call(t_stack *a)
{
    a->top = a->top->next;
}