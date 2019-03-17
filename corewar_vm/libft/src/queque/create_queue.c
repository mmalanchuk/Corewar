/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:59:02 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 15:59:04 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_qnode	*new_qnode(void *data)
{
	t_qnode	*node;

	node = malloc(sizeof(t_qnode));
	node->data = data;
	node->next = NULL;
	return (node);
}

t_queue	*create_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}
