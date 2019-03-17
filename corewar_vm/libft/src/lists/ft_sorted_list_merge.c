/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:29:05 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:29:07 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sorted_list_merge(t_list **alst, t_list *blst, int (*cmp)())
{
	bool	sorted;
	t_list	*head1;
	t_list	*head2;
	t_list	*tail;

	PROTECT_VOID(!alst || !blst || !*cmp);
	if (!*alst)
	{
		*alst = blst;
		return ;
	}
	sorted = cmp(blst->content, (*alst)->content) < 0;
	head1 = sorted ? *alst : (*alst)->next;
	head2 = sorted ? blst->next : blst;
	*alst = sorted ? blst : *alst;
	tail = *alst;
	while (head1 && head2)
	{
		sorted = cmp(head2->content, head1->content) < 0;
		tail->next = sorted ? head2 : head1;
		head1 = sorted ? head1 : head1->next;
		head2 = sorted ? head2->next : head2;
		tail = tail->next;
	}
	tail->next = head2 ? head2 : head1;
}
