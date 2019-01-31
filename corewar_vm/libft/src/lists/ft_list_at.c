#include "libft.h"

t_list	*ft_lst_get_index(t_list *lst, unsigned int index)
{
	unsigned int i;

	if (index > ft_list_size(lst) - 1 || ft_is_empty(lst))
		return (NULL);
	i = 0;
	while (i < index)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}