/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:04:04 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/06 15:04:07 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;

	if (ft_is_empty(*begin_list))
		*begin_list = ft_lstnew(data, sizeof(data));
	else
	{
		temp = *begin_list;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(data, sizeof(data));
	}
}
