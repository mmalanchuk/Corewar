#include "corewar_vm.h"

t_process *init_process(int id)
{
	t_process *new;

	new = (t_process *)ft_memalloc(sizeof(t_process));
	if (new == NULL)
		throw_error(MEM_ALLOC_ERR, NULL);
	new->id = id;
	new->next = NULL;
	new->carry = false;
	new->cycles_left = -1;
	new->last_live_cycles = -1;
	new->pc = -1;
	new->registry[0] = -id;
	return (new);
}

void	to_process_list(t_process **lst, t_process *proc)
{
	if (!lst || !proc)
		return ;
	if (!*lst)
		*lst = proc;
	else
	{
		proc->next = *lst;
		*lst = proc;
	}
}

t_process *get_processes(t_env *vm)
{
	t_process *lst;
	int			i;

	lst = NULL;
	i = 0;
	while (i < vm->players_num)
	{
		to_process_list(&lst, init_process(PLAYER[i]->id));
		i++;
	}
	return (lst);
}