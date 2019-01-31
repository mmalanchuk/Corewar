#include "corewar_vm.h"

/**
 * set_arg_type				sets types for each args
 * @param args				arg_type array
 * @param codage_byte		byte that stands for all arg types of the current op
 */

void	decode_type_code(t_arg_type *args, int32_t codage_byte)
{
	args[0] = (t_arg_type)(codage_byte >> 6 & 3);
	args[1] = (t_arg_type) (codage_byte >> 4 & 3);
	args[2] = (t_arg_type) (codage_byte >> 2 & 3);
}

void	copy_arg_types(t_arg_type *args, t_arg_type *new_types)
{
	args[0] = new_types[0];
	args[1] = new_types[1];
	args[2] = new_types[2];
}

/**
 * bool check_arg_types checks if read arg types are valid
 *
 * @param curr_types	arg types to check
 * @param op			current operation
 * @return				bool if valid
 */

bool check_arg_types(const t_arg_type curr_types[], t_op op)
{
	int i;

	i = 0;
	while (i < op.arg_num)
	{
		if (!(curr_types[i] & op.arg_type[i]))
			return (false);
		i++;
	}
	return (true);
}

void calc_pc_step(t_process * pointer)
{
	int i;

	i = 0;
	STEP = 0;
	while (i < OP.arg_num)
	{
		if (ARG_TYPE[i] == T_REG)
			STEP += REG_IDX_SIZE;
		else if (ARG_TYPE[i] == T_DIR)
			STEP += DIR_SIZE >> OP.t_dir_size_diff;
		else if (ARG_TYPE[i] == T_IND)
			STEP += IND_SIZE;
		i++;
	}
}

/**
 * read_arg_types read a 1 Byte to arg types and validate
 * @param vm
 * @param pointer
 */

bool set_arg_types(t_env *vm, t_process *pointer)
{
	t_arg_type temp[MAX_ARGS_NUMBER];

	if (OP.arg_codes){
		decode_type_code(ARG_TYPE, read_bytes(ARENA, PC, 1));
		PC++;
	}
	else
		copy_arg_types(ARG_TYPE, OP.arg_type);
	calc_pc_step(pointer);
	return (check_arg_types(temp, OP));
}

