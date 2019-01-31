#include "libft.h"

void	btree_dfs_postorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || !*applyf)
		return ;
	btree_dfs_postorder(root->right, applyf);
	btree_dfs_postorder(root->left, applyf);
	applyf(root->item);
}