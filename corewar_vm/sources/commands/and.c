#include "corewar_vm.h"

void op_and(t_env *vm)
{
	if (get_arg_types(vm) == false)
		return ;
	get_args(vm, false);
	if (ARG_TYPE[0] == T_REG && is_registry_id(ARG[0]))
		ARG[0] = REG[IDX(ARG[0])];
	if (ARG_TYPE[1] == T_REG && is_registry_id(ARG[1]))
		ARG[1] = REG[IDX(ARG[1])];
	if (is_registry_id(ARG[2]))
	{
		REG[IDX(ARG[2])] = ARG[0] & ARG[1];
		CARRY = REG[IDX(ARG[2])] == 0;
	}
}
