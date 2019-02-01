/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:35:03 by adayrabe          #+#    #+#             */
/*   Updated: 2019/02/01 14:35:04 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assign(t_operation *temp, int l)
{
	temp->label1 = NULL;
	temp->label2 = NULL;
	temp->position1 = 0;
	temp->position2 = 0;
	temp->line = l;
	temp->code = NULL;
	temp->length = 0;
	temp->next = NULL;
}

void	add_operation(t_address *head, int l)
{
	t_operation	*temp;
	t_address	*addr;

	addr = head;
	while (addr->next)
		addr = addr->next;
	if (!addr->operations)
	{
		addr->operations = (t_operation *)malloc(sizeof(t_operation));
		temp = addr->operations;
	}
	else
	{
		temp = addr->operations;
		while (temp->next)
			temp = temp->next;
		temp->next = (t_operation *)malloc(sizeof(t_operation));
		temp = temp->next;
	}
	assign(temp, l);
}
