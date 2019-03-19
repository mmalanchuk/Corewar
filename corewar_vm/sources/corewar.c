#include "corewar_vm.h"
#include "debug.h"

/**
 * init_arena()		initializes arena copying players code in correct place
 * @param vm
 * @param vm->pointer
 */

//TODO main cycle for vm


void init_arena(t_env *vm)
{
	int pos;
	int i;
	t_process *curr;

	pos = 0;
	i = 0;
	while (i < vm->players_num)
	{
		ft_memcpy(&vm->arena[pos], PLAYER[i]->code, PLAYER[i]->code_size);
		PC = pos;
		pos += MEM_SIZE/vm->players_num;
		curr= curr->next;
		i++;
	}
}

void play_corewar(t_env *vm)
{
	init_arena(vm);
#ifdef DEBUG
	print_processes_list(vm->pointer);
	print_arena(vm);
#endif
	introduce_contestants(vm);
	run_vm_cycle(vm);
}