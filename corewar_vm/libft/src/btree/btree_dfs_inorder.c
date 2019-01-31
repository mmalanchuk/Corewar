#include "libft.h"

void	btree_dfs_inorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || !*applyf)
		return ;
	btree_dfs_inorder(root->left, applyf);
	applyf(root->item);
	btree_dfs_inorder(root->right, applyf);
}