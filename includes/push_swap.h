#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

void			push_swap(int *a, int argc);
int				is_sorted(long long int *a, int argc);
void			push_swap_error(void);


long long int	binary(int num);
long long int	power(int power);

long long int	*fill_tab(int argc, char **argv, long long int *tab);
long long int	special_atoi(char *tab);
long long int	*simplify(long long int *a, int argc);
long long int	*sort(long long int *tab, int argc);

int				check_args(char *tab);
int				check_args_length(char *tab);
int				is_numeric(char *tab);
void			check_duplicates(long long int *tab, int argc);

#endif