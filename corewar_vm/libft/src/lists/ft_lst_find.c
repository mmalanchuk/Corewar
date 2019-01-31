#include "libft.h"

t_list *ft_list_find(t_list *alst, void *data_ref, int (*cmp)())
{
	while (alst)
	{
		if (cmp(alst->content, data_ref) == 0)
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}