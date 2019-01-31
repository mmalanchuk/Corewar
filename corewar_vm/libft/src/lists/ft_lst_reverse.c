#include "libft.h"

void	ft_lst_reverse(t_list **alst)
{
	t_list	*temp;
	t_list	*reversed;

	if (ft_is_empty(alst) || ft_is_empty(*alst))
		return ;
	reversed = NULL;
	while (*alst)
	{
		temp = (*alst)->next;
		(*alst)->next = reversed;
		reversed = *alst;
		*alst = temp;
	}
	*alst = reversed;
}