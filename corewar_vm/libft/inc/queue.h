#ifndef QUEUE_H
# define QUEUE_H
# include "libft.h"

struct s_qnode
{
	void			*data;
	struct s_qnode	*next;
};

typedef struct s_qnode	t_qnode;

struct s_queue
{
	t_qnode	*front;
	t_qnode	*rear;
	size_t	size;
};

typedef struct s_queue	t_queue;

t_queue *create_queue(void);
t_qnode	*new_qnode(void *data);
void	enqueue(t_queue *q, void *data);
void	*dequeue(t_queue *q);
void	print_queue(t_queue *queue);
void 	del_queue(t_queue *queue);

#endif