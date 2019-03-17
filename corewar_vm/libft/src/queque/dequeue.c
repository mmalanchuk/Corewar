/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:00:04 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:00:12 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*dequeue(t_queue *q)
{
	void	*value;
	t_qnode	*temp;

	if (q == NULL || ft_is_empty(q->front))
		return (NULL);
	if (q->front == q->rear)
	{
		value = q->front->data;
		free(q->front);
		q->rear = NULL;
		q->front = NULL;
	}
	else
	{
		temp = q->front;
		value = q->front->data;
		q->front = q->front->next;
		free(temp);
	}
	q->size--;
	return (value);
}
