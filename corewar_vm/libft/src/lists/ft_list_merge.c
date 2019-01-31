#include "libft.h"

void	ft_list_merge(t_list **alst, t_list *blst)
{
	t_list *lst_ptr;

	if (!alst || !blst)
		return ;
	if (*alst)
	{
		lst_ptr = *alst;
		while (lst_ptr->next)
			lst_ptr = lst_ptr->next;
		lst_ptr->next = blst;
	}
	else
		*alst = blst;
}