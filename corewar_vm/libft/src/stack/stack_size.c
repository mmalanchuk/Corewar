/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:24:14 by mmalanch          #+#    #+#             */
/*   Updated: 2018/10/07 15:24:15 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	stack_size(t_stack *stack)
{
	size_t stack_size;

	stack_size = 0;
	while (!ft_is_empty(stack))
	{
		stack_size++;
		stack = stack->next;
	}
	return (stack_size);
}
