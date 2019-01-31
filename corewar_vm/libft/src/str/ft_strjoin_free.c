#include "str.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *ret;

	PROTECT(s1 && s2)
	PROTECT(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2)))
	ret = ft_strcat(ft_strcat(ret, s1), s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ret);
}
