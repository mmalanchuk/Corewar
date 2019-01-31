#include "queue.h"

t_qnode	*new_qnode(void *data)
{
	t_qnode	*node;

	node = malloc(sizeof(t_qnode));
	node->data = data;
	node->next = NULL;

	return (node);
}

t_queue *create_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}