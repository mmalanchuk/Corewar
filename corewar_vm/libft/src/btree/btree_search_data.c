#include "libft.h"

t_btree	*btree_search_item(t_btree *root, void *data_ref, int (*cmp)(void *, void *))
{
	t_btree *found;

	if (!root || !data_ref || !*cmp)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmp);
	if (!found && cmp(root->item, data_ref) == 0)
		found = root;
	if (!found)
		found = btree_search_item(root->right, data_ref, cmp);
	return (found);
}