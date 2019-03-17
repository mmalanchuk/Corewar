#include "corewar_vm.h"

void op_lfork(t_env *vm, t_process *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	copy_carriage(vm, pointer, PC + ARG[0]);

}