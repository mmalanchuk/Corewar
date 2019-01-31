#ifndef MATH_H
# define MATH_H

# include <stddef.h>

# define FT_ABS(x)		(((x) < 0) ? -(x) : (x))
# define FT_MAX(a, b) ((a) > (b) ? (a) : (b))
# define FT_MIN(a, b) ((a) < (b) ? (a) : (b))


size_t	ft_factorial(size_t num);
size_t	ft_pow(int num, int power);

#endif