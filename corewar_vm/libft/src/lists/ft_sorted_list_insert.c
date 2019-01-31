#include "libft.h"

void	ft_sorted_list_insert(t_list **alst, void *data, int (*cmp)())
{
	t_list	*link;
	t_list	*insert;
	if (!alst || !data || !*cmp)
		return;
	link = *alst;
	insert = ft_lstnew(data, sizeof(data));
	if (!link || cmp(data, link->content) < 0)
	{
		*alst = insert;
		insert->next = link ? link : NULL;
		return;
	}
	while (link->next)
	{
		if ((cmp(data, link->content) > 0) && cmp(data, link->next->content) <= 0)
		{
			insert->next = link->next;
			link->next = insert;
			return ;
		}
		link = link->next;
	}
	link->next = insert;
	insert->next = NULL;
}
