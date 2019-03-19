#include "corewar_vm.h"

void op_ld(t_env *vm)
{
	if (get_arg_types(vm) == false)
		return ;
	get_args(vm, false);
	if (is_registry_id(ARG[1]))
	{
		REG[IDX(ARG[1])] = ARG[0];
		CARRY = REG[IDX(ARG[1])] == 0;
	}
}