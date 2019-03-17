/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:05:59 by mmalanch          #+#    #+#             */
/*   Updated: 2019/02/26 20:06:00 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item, size_t item_size)
{
	t_btree	*node;

	PROTECT(node = malloc(sizeof(t_btree)));
	if (item == NULL)
	{
		node->item = item;
		node->content_size = 0;
	}
	else
	{
		node->item = ft_memalloc(item_size);
		if (!node->item)
		{
			free(node);
			return (NULL);
		}
		ft_memcpy(node->item, item, item_size);
		node->content_size = item_size;
	}
	node->left = NULL;
	node->right = NULL;
	return (node);
}
