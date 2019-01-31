#include "libft.h"

void	btree_dfs_preorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || !*applyf)
		return ;
	applyf(root->item);
	btree_dfs_preorder(root->left, applyf);
	btree_dfs_preorder(root->right, applyf);
}