/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:56:41 by adayrabe          #+#    #+#             */
/*   Updated: 2018/01/28 16:56:44 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **head, t_list *elem)
{
	t_list *temp;

	if (!head)
		return ;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
}
