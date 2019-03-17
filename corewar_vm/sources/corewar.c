#include "corewar_vm.h"
#include "debug.h"

/**
 * init_arena()		initializes arena copying players code in correct place
 * @param vm
 * @param pointer
 */

//TODO main cycle for vm


void init_arena(t_env *vm, t_process *pointer)
{
	int pos;
	int i;

	pos = 0;
	i = 0;
	while (i < vm->players_num)
	{
		ft_memcpy(&vm->arena[pos], PLAYER[i]->code, PLAYER[i]->code_size);
		PC = pos;
		pos += MEM_SIZE/vm->players_num;
		pointer = pointer->next;
		i++;
	}
}

void play_corewar(t_env *vm, t_process *pointer)
{
	init_arena(vm, pointer);
#ifdef DEBUG
	print_processes_list(pointer);
	print_arena(vm);
#endif
	introduce_contestants(vm);
	run_vm_cycle(vm, pointer);
}