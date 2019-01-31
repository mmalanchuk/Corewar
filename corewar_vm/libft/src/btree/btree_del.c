#include "btree.h"

void	btree_del(t_btree **root, void (*del_content)(void *, size_t))
{
	if (!root || !*root || !*del_content)
		return ;
	btree_del(&(*root)->left, del_content);
	btree_del(&(*root)->right, del_content);
	btree_delone(root, del_content);
}