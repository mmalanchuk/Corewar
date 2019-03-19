#include "corewar_vm.h"
/*
 * Во время этой проверки каретки, которые являются мертвыми, удаляются из списка.

Как определить, что каретка мертва?

Мертвой считается каретка, которая выполняла операцию live cycles_to_die циклов назад или более.

Также мертвой считается любая каретка, если cycles_to_die <= 0.
 */


bool	need_to_remove(t_env *vm)
{
	return (vm->cycles_to_die <= 0 ||
			vm->cycle - vm->pointer->last_live_cycle >=  vm->cycles_to_die);
}
//TODO correct removing carriages to avoid leak
bool	carriage_remove_if(t_env *vm)
{
	bool one_alive;
	t_process *prev;
	t_process *curr;

	curr = vm->pointer;
	one_alive = false;
	prev = NULL;
	while (curr)
	{
		if (need_to_remove(vm))
		{
			if (prev)
				prev->next = curr->next;;
			ft_memdel((void **) &curr);
			vm->cursors--;
			if (prev)
				curr= prev->next;
		}
		else
		{
			prev = curr;
			one_alive = true;
			curr= curr->next;
		}
	}
	return(one_alive);
}

void	reset_player_lives(t_env *vm)
{
	int i;

	i = 0;
	while (i < vm->players_num)
	{
		vm->players[i]->lives = 0;
		i++;
	}
	vm->lives_in_period = 0;
}

bool check_alive(t_env *vm)
{
	bool	one_alive;

	vm->checks_count++;
	one_alive = carriage_remove_if(vm);
	//Если MAX_CHECKS проверок спустя значение cycles_to_die не изменится, то оно будет принудительно уменьшено на значение CYCLE_DELTA.
	if (vm->checks_count == MAX_CHECKS || vm->lives_in_period >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks_count = 0;
	}
	vm->cycles_after_check = 0;
	reset_player_lives(vm);
	return (one_alive);
}
