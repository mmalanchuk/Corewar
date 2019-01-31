
#include "str.h"

int	ft_str_count_occur(const char *str, char c)
{
	int count;
	int i;

	if (str == NULL)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		count += str[i] == c;
		i++;
	}
	count += str[i] == c;
	return (count);
}