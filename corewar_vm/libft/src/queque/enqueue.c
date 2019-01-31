#include "queue.h"


void	enqueue(t_queue *q, void *data)
{
	t_qnode *node;

	if (q == NULL)
		return ;
	node = new_qnode(data);
	if (ft_is_empty(q->rear))
	{
		q->front = node;
		q->rear = node;
	}
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
	q->size++;
}


