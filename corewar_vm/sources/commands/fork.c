#include "corewar_vm.h"

void op_fork(t_env *vm, t_process *pointer)
{
	if (set_arg_types(vm, pointer) == false)
		return(step_over(pointer));
	get_args(vm, pointer, false);
	copy_process(vm, pointer, PC + ARG[0] % IDX_MOD);
}