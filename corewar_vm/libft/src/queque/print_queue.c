/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:00:46 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:01:01 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static void	print_node(t_qnode *front)
{
	if (front == NULL)
		ft_printf("%s\n", NULL);
	else
	{
		ft_printf("[%s]->", front->data);
		print_node(front->next);
	}
}

void		print_queue(t_queue *queue)
{
	if (!queue)
		return ;
	print_node(queue->front);
}
