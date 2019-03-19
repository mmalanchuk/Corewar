#include "corewar_vm.h"

void op_aff(t_env *vm)
{
	if (get_arg_types(vm) == false)
		return ;
	get_args(vm, false);
	if (is_registry_id(ARG[0]))
		ft_printf("Aff: %s\n", REG[IDX(ARG[0])]);
}