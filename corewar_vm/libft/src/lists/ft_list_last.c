#include "libft.h"

t_list	*ft_list_last(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}