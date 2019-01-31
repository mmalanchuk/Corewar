#include "libft.h"

void btree_insert_data(t_btree **root, void *item, size_t content_size, int (*cmpf)(void *, void *))
{
	if (!*cmpf || !root)
		return ;
	if (*root == NULL)
	{
		*root = btree_create_node(item, content_size);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, content_size, cmpf);
	else
		btree_insert_data(&(*root)->right, item, content_size, cmpf);

}
