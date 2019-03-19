#include "corewar_vm.h"

void op_lfork(t_env *vm)
{
	if (get_arg_types(vm) == false)
		return ;
	get_args(vm, false);
	copy_carriage(vm, PC + ARG[0]);

}