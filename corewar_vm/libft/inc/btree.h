/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:04:13 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:05:08 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H
# include "libft.h"

struct	s_btree
{
	void			*item;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
};

typedef struct s_btree	t_btree;

t_btree	*btree_create_node(void *item, size_t item_size);
void	btree_dfs_preorder(t_btree *root, void (*applyf)(void *));
void	btree_dfs_inorder(t_btree *root, void (*applyf)(void *));
void	btree_dfs_postorder(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **root, void *item, size_t content_size,
		int (*cmpf)(void *, void *));
t_btree	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmp)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_del(t_btree **root, void (*del_content)(void *, size_t));
void	btree_delone(t_btree **root, void (*del_content)(void *, size_t));

void	btree_print(t_btree *btree);

#endif
