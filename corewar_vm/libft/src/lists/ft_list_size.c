#include "libft.h"

size_t	ft_list_size(t_list *begin_list)
{
	size_t size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}