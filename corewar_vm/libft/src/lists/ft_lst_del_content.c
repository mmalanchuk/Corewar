#include "libft.h"

void	ft_lst_del_content(void *ptr, size_t size)
{
	(void)size;
	ft_memdel(&ptr);
}
