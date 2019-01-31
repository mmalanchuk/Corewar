#include "libft.h"

int btree_level_count(t_btree *root)
{
	if (!root)
		return 0;
	return (1 + FT_MAX(btree_level_count(root->left),
							  btree_level_count(root->right)));
}
