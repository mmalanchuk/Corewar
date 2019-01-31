#include "btree.h"

void	btree_delone(t_btree **root, void (*del_content)(void *, size_t))
{
	if (!root || !*root || !*del_content)
		return ;
	del_content((*root)->item, (*root)->content_size);
	free(*root);
	*root = NULL;
}