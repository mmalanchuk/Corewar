#include "corewar_vm.h"

void op_ld(t_env *vm, t_process *pointer)
{
	if (set_arg_types(vm, pointer) == false)
		return(step_over(pointer));
	get_args(vm, pointer, false);
	if (is_registry_id(ARG[1]))
	{
		REG[IDX(ARG[1])] = ARG[0];
		CARRY = ARG[0] != 0;
	}
}