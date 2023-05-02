#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

void		push_swap(t_stack *stack_a, t_stack *stack_b);
int			is_sorted(t_module	*top, t_module *bottom);
void		push_swap_error(void);

void		five(t_stack *stack_a);
t_module	*compare(t_stack *stack, t_module *current);
void		swap(t_stack *stack, t_module *current);

void		hundred(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *a, t_stack *b);
int			check(t_stack *a, int med, int flag);
int			rot_or_revrot(t_stack *a, int med);
void		rot(t_stack *a, t_stack *b, int med, int flag);
void	    second_push(t_stack *a, t_stack *b);

void       five_hundred(t_stack *a, t_stack *b);
void        push_b_five(t_stack *a, t_stack *b, int flag, int medinf);
void    	rot_five(t_stack *a, t_stack *b, int medinf, int medsupp);
int	        rot_or_revrot_five(t_stack *a, int medinf, int medsupp);
int	        check_five(t_stack *stack, int medsupp, int medinf);

void		push_a(t_stack *a, t_stack *b);
void		find(t_stack *stack);
void		reverse(t_stack *b, t_stack *a, int flag);
int			how_close(t_stack *b);

void		median(t_stack *stack);
void		swap_median(t_module *top, t_module *current);
t_module	*fill_tmp(t_stack *tmp, t_stack *stack);
void		sort(t_stack *tmp);
void		find_median(t_stack	*tmp, t_stack *stack);
void		free_median(t_stack *tmp);

void		five_hundred(t_stack *stack_a, t_stack *stack_b);

t_module	*fill_stack(int argc, char **argv, t_stack **stack);
void		fill_node(char *argv, t_module **node, t_stack **stack);
t_module	*init_node(void);
t_stack		*init_stack(void);
int			special_atoi(char *tab);

int			check_args(char *tab);
int			check_args_length(char *tab);
int			is_numeric(char *tab);
void		linking(t_module **tmp, t_module **node, t_stack **stack);
void		check_duplicates(t_stack	*a);
void		free_everything(t_stack *stack_a, t_stack *stack_b);
void		relink(t_stack *a, t_stack *b, t_module *tmp);


void		cmd_sa( );
void		cmd_sb( );
void		cmd_pa( );
void		cmd_pb( );
void		cmd_ra( );
void		cmd_rb( );
void		cmd_rra( );
void		cmd_rrb();


#endif
/*
2.<=100;
3.<=500:
 */