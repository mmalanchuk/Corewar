#include "libft.h"

void	btree_print(t_btree *btree)
{
	if (!btree)
		return ;
	btree_dfs_preorder(btree, (void (*)(void *)) &ft_putendl);
//	ft_printf("[%s]\n", btree->item);
}