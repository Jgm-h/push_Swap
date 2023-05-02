#include "push_swap.h"

long long int	binary(int num)
{
	long long int	binnumber;
	int				pow;
	long long int	temp;
	int				rem;

	binnumber = 0;
	pow = 0;
	while (num > 0)
	{
		rem = num % 2;
		temp = power(pow);
		binnumber += rem * temp;
		pow++;
		num /= 2;
	}
	return (binnumber);
}

long long int	power(int power)
{
	int	base;

	base = 10;
	while (power)
	{
		base *= 10;
		power--;
	}
	return (base);
}
