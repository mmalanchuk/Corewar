/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:05 by mmalanch          #+#    #+#             */
/*   Updated: 2019/02/26 20:07:08 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_print(t_btree *btree)
{
	if (!btree)
		return ;
	btree_dfs_preorder(btree, (void (*)(void *)) &ft_putendl);
}
