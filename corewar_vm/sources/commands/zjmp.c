#include "corewar_vm.h"

void op_zjmp(t_env *vm, t_process *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (CARRY)
	{
		PC += ARG[0] % IDX_MOD;
		STEP = 0;
	}
}