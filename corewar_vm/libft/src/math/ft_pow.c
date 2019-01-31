#include "ft_math.h"

size_t	ft_pow(int num, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num *= ft_pow(num, power - 1);
	return (size_t)(num);
}