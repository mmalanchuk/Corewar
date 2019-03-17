/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:28:57 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:28:58 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_merge(t_list **alst, t_list *blst)
{
	t_list *lst_ptr;

	if (!alst || !blst)
		return ;
	if (*alst)
	{
		lst_ptr = *alst;
		while (lst_ptr->next)
			lst_ptr = lst_ptr->next;
		lst_ptr->next = blst;
	}
	else
		*alst = blst;
}
