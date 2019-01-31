/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                    :+:         :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:24:20 by mmalanch          #+#    #+#             */
/*   Updated: 2018/10/07 15:24:21 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_stack	*stack_create_node(void *data)
{
	t_stack *stack_node;

	stack_node = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack_node->data = data;
	stack_node->next = NULL;
	return (stack_node);
}

void			stack_push(t_stack **root_ptr, void *data)
{
	t_stack *node;

	if (!data || !root_ptr)
		return ;
	node = stack_create_node(data);
	node->next = *root_ptr;
	*root_ptr = node;
}
