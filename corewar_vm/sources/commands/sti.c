#include "corewar_vm.h"

void op_sti(t_env *vm)
{
	if (get_arg_types(vm) == false)
		return ;
	get_args(vm, false);
	if(is_registry_id(ARG[0]))
	{
		if (ARG_TYPE[1] == T_REG && is_registry_id(ARG[1]))
			ARG[1] = REG[IDX(ARG[1])];
		if (ARG_TYPE[2] == T_REG && is_registry_id(ARG[2]))
			ARG[2] = REG[IDX(ARG[2])];
		ADDR = (ARG[1] + ARG[2]) % IDX_MOD;
		write_to_arena(vm, REG[IDX(ARG[0])]);
	}
}