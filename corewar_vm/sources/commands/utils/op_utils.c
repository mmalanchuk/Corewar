#include "corewar_vm.h"

/**
 *	is_player_id	checks if id is valid
 *	is_registry_id	checks if register  number is valid
 */

bool	is_player_id(t_env *vm, int id)
{
	return (id > 0 && id <= vm->players_num);
}

bool	is_registry_id(int id)
{
	return (id >= 1 && id <= REG_NUMBER);
}

/**
 * ?????????????????????????????????????????
 * @param value
 * @return
 */

//TODO convert & write

uint8_t *convert_int32_to_int8(int32_t value)
{

}

void	write_to_arena(t_env *vm, t_process *pointer, int32_t value)
{
	uint8_t *bytes;
	int i;

	bytes = convert_int32_to_int8(value);
	i = 0;
	while (i < REG_SIZE)
	{
		ARENA[PC + ADDR + i] = bytes[i];
		i++;
	}
}

void	step_over(t_process *pointer)
{
	PC += STEP;
}

void	copy_process(t_env *vm, t_process *pointer, int where)
{

}