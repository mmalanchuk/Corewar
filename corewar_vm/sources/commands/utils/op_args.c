#include "corewar_vm.h"

int32_t	get_reg_index(t_env *vm, t_process *pointer)
{
	return (read_bytes(ARENA, PC, REG_IDX_SIZE));
}

int32_t	get_dir_value(t_env *vm, t_process *pointer)
{
	return (read_bytes(ARENA, PC + ADDR, DIR_SIZE >> OP.t_dir_size_diff));
}

int32_t	get_ind_value(t_env *vm, t_process *pointer)
{
	int32_t addr;

	addr = read_bytes(ARENA, PC, IND_SIZE);
	ADDR = OP.idx_mod ? addr % IDX_MOD : addr;
	return (get_dir_value(vm, pointer));
}

/**
 * get_arg_value fills args array with args of corresponding types
 * @param vm
 * @param pointer
 */

void get_args(t_env *vm, t_process *pointer, bool return_ind_addr)
{
	int n;

	n = 0;
	while (ARG_TYPE[n])
	{
		if (pointer->arg_type[n] == T_REG)
		{
			ARG[n] = get_reg_index(vm, pointer);
			PC += REG_IDX_SIZE;
		}
		else if (pointer->arg_type[n] == T_DIR)
		{
			ARG[n] = get_dir_value(vm, pointer);
			PC += DIR_SIZE >> OP.t_dir_size_diff;
		}
		else if (pointer->arg_type[n] == T_IND)
		{
			ARG[n] = return_ind_addr ? read_bytes(ARENA, PC, IND_SIZE)
									 : get_ind_value(vm, pointer);
			PC += IND_SIZE;
		}
		n++;
	}
	ADDR = 0;
}
