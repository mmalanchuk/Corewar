#include "libft.h"

void		ft_list_sort(t_list **alst, int (*cmp)())
{
	t_list	**list_ptr;
	t_list	*tmp;
	t_list	*tmp2;

	if (!alst || !*alst || !*cmp)
		return ;
	list_ptr = alst;
	while (*list_ptr && (*list_ptr)->next)
	{
		if (cmp((*list_ptr)->content, (*list_ptr)->next->content) > 0)
		{
			tmp = *list_ptr;
			tmp2 = (*list_ptr)->next;
			(*list_ptr)->next = (*list_ptr)->next->next;
			*list_ptr = tmp2;
			(*list_ptr)->next = tmp;
			list_ptr = alst;
		}
		else
			list_ptr = &(*list_ptr)->next;
	}
}
