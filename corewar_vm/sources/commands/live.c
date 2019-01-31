#include "corewar_vm.h"

void op_live(t_env *vm, t_process *pointer)
{
	if (set_arg_types(vm, pointer) == false)
		return(step_over(pointer));
	get_args(vm, pointer, false);
	pointer->last_live_cycles = vm->cycle;
	if (is_player_id(vm, ARG[0]))
	{
		PLAYER[IDX(ARG[0])]->last_live_cycles = vm->cycle;
		PLAYER[IDX(ARG[0])]->lives++;
	}
}