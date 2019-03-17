/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:06:52 by mmalanch          #+#    #+#             */
/*   Updated: 2019/02/26 20:06:53 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_delone(t_btree **root, void (*del_content)(void *, size_t))
{
	if (!root || !*root || !*del_content)
		return ;
	del_content((*root)->item, (*root)->content_size);
	free(*root);
	*root = NULL;
}
