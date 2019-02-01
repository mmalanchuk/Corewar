#include "corewar_vm.h"
#include "debug.h"

/**
 * init_arena()		initializes arena copying players code in correct place
 * @param vm
 * @param pointer
 */

void init_arena(t_env *vm, t_process *pointer)
{
	int pos;
	int i;

	pos = 0;
	i = vm->players_num - 1;
	while (i >= 0)
	{
		ft_memcpy(&vm->arena[pos], PLAYER[i]->code, PLAYER[i]->code_size);
		PC = pos;
		pos += MEM_SIZE/vm->players_num;
		pointer = pointer->next;
		i--;
	}
}

void get_current_op(t_env *vm, t_process *pointer)
{
	int op_code;

	op_code = read_bytes(ARENA, PC, OP_SIZE);
	PC += OP_SIZE;
	if (op_code >= 1 && op_code <= 16)
		OP = op_tab[IDX(op_code)];
}

void play_corewar(t_env *vm, t_process *pointer)
{
	init_arena(vm, pointer);
#ifdef DEBUG
	print_processes_list(pointer);
	print_arena(vm);
#endif
	get_current_op(vm, pointer);
	OP.f_ptr(vm, pointer);

}