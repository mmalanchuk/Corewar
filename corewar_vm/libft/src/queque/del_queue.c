
#include "queue.h"

void 	del_queue(t_queue *queue)
{
	while (queue->size != 0)
		dequeue(queue);
	ft_memdel((void **)&queue);
}