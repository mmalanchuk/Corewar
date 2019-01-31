#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;

	if (ft_is_empty(*begin_list))
		*begin_list = ft_lstnew(data, sizeof(data));
	else
	{
		temp = *begin_list;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(data, sizeof(data));
	}
}