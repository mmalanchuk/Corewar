#include "corewar_vm.h"

void op_add(t_env *vm, t_process *pointer)
{
	if (set_arg_types(vm, pointer) == false)
		return(step_over(pointer));
	get_args(vm, pointer, false);
	if (is_registry_id(ARG[0]) && is_registry_id(ARG[1]) && is_registry_id(ARG[2]))
		REG[IDX(ARG[2])] = REG[IDX(ARG[0])] + REG[IDX(ARG[1])];
	CARRY = REG[IDX(ARG[2])] != 0;
}