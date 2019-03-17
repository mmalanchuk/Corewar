/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:05:16 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/06 15:05:18 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_sort(t_list **alst, int (*cmp)())
{
	t_list	**list_ptr;
	t_list	*tmp;
	t_list	*tmp2;

	if (!alst || !*alst || !*cmp)
		return ;
	list_ptr = alst;
	while (*list_ptr && (*list_ptr)->next)
	{
		if (cmp((*list_ptr)->content, (*list_ptr)->next->content) > 0)
		{
			tmp = *list_ptr;
			tmp2 = (*list_ptr)->next;
			(*list_ptr)->next = (*list_ptr)->next->next;
			*list_ptr = tmp2;
			(*list_ptr)->next = tmp;
			list_ptr = alst;
		}
		else
			list_ptr = &(*list_ptr)->next;
	}
}
