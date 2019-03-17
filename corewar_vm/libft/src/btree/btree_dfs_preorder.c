/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_dfs_preorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:06:40 by mmalanch          #+#    #+#             */
/*   Updated: 2019/02/26 20:06:41 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_dfs_preorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || !*applyf)
		return ;
	applyf(root->item);
	btree_dfs_preorder(root->left, applyf);
	btree_dfs_preorder(root->right, applyf);
}
