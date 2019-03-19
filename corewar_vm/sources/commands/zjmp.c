#include "corewar_vm.h"

void op_zjmp(t_env *vm)
{
	if (get_arg_types(vm) == false)
		return ;
	get_args(vm, false);
	if (CARRY)
	{
		PC += ARG[0] % IDX_MOD;
		STEP = 0;
	}
}