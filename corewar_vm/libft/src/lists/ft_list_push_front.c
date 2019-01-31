#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	ft_lstadd(begin_list, ft_lstnew(data, sizeof(data)));
}