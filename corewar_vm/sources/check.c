#include "corewar_vm.h"
/*
 * Во время этой проверки каретки, которые являются мертвыми, удаляются из списка.

Как определить, что каретка мертва?

Мертвой считается каретка, которая выполняла операцию live cycles_to_die циклов назад или более.

Также мертвой считается любая каретка, если cycles_to_die <= 0.
 */


bool	need_to_remove(t_env *vm, t_process *pointer)
{
	return (vm->cycles_to_die <= 0 ||
			vm->cycle - pointer->last_live_cycle >=  vm->cycles_to_die);
}

//TODO write delete function

bool	kill_carriages(t_env *vm, t_process * pointer)
{
	bool one_alive;

	one_alive = false;
	while (pointer)
	{
		if (need_to_remove(vm, pointer))
		{
			pointer->is_ded = true;
			vm->cursors--;
		}
		else
			one_alive = true;
		pointer = pointer->next;
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
bool check_alive(t_env *vm, t_process *pointer)
{
	bool	one_alive;

	vm->checks_count++;
	one_alive = kill_carriages(vm, pointer);
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
