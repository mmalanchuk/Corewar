#include "corewar_vm.h"

void op_aff(t_env *vm, t_process *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (is_registry_id(ARG[0]))
		ft_printf("Aff: %s\n", REG[IDX(ARG[0])]);
}