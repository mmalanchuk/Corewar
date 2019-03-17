/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:04:59 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/06 15:05:00 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *alst, void *data_ref, int (*cmp)())
{
	while (alst)
	{
		if (cmp(alst->content, data_ref) == 0)
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}
