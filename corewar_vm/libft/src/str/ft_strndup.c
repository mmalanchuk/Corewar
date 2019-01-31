#include "str.h"

char	*ft_strndup(const char *src, size_t	n)
{
	char	*dest;

	PROTECT(src);
	PROTECT(dest = ft_strnew(n));
	return (ft_strncpy(dest, src, n));
}
