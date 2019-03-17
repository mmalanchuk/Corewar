/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:25:25 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:25:26 by mmalanch         ###   ########.fr       */
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
