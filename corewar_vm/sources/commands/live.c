#include "corewar_vm.h"

void op_live(t_env *vm)
{
	vm->lives_in_period++;
	vm->pointer->last_live_cycle = vm->cycle;

	if (get_arg_types(vm) == false)
		return ;
	get_args(vm, false);
	if (is_player_id(vm, ARG[0]))
	{
		PLAYER[IDX(FT_ABS(ARG[0]))]->last_live_cycle = vm->cycle;
		PLAYER[IDX(FT_ABS(ARG[0]))]->lives++;
		vm->last_alive = FT_ABS(ARG[0]);
	}
}