/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:16:40 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:16:41 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

struct	s_stack
{
	void				*data;
	struct s_stack		*next;
};

typedef struct s_stack	t_stack;

void	stack_push(t_stack **root_ptr, void *data);
void	*stack_pop(t_stack **root_ptr);
void	*stack_peek(t_stack *root);
size_t	stack_size(t_stack *stack);
#endif
