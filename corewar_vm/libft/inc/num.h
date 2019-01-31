#ifndef NUM_H
# define NUM_H

# include "libft.h"

# define FT_EXSPACE(x)	((FT_SPACE(x))|| (x) == '\r' || (x) == '\f' || (x) == '\v')
# define FT_LCASE(x)	((x) >= 97 && (x) <= 122)

size_t	ft_numlen(int n);
bool	ft_in_base(char c, int base);

int		ft_atoi_base(const char *str, int base);
char	*ft_itoa_base(int n, int base);
char	*ft_itoa(int n);
long	ft_strtol(const char *str, char **endptr, int base);

#endif