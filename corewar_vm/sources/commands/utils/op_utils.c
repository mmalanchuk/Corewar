#include "corewar_vm.h"

/**
 *	is_player_id	checks if id is valid
 *	is_registry_id	checks if register  number is valid
 */

bool	is_player_id(t_env *vm, int id)
{
	return (id <= -1 && id <= -vm->players_num);
}

bool	is_registry_id(int id)
{
	return (id >= 1 && id <= REG_NUMBER);
}

/**
 * Converts uint32_t to uint_8_t
 * @param value
 * @return
 */

uint8_t *convert_int32_to_int8(uint32_t value)
{
	uint8_t		*res;
	int			i;

	i = 3;
	res = (uint8_t *)ft_memalloc(4 * sizeof(uint8_t));
	while (i >= 0)
	{
		// val & 0xFF  value >> 8
		res[i] = (uint8_t)(value % 256);
		value /= 256;
		i--;
	}
	return (res);
}

/**
 * Write to ARENA array of uint8_t
 * @param vm
 * @param pointer
 * @param value
 */

void	write_to_arena(t_env *vm, t_process *pointer, int32_t value)
{
	uint8_t *bytes;
	int i;
	int addr;

	bytes = convert_int32_to_int8((uint32_t)value);
	i = 0;
	while (i < REG_SIZE)
	{
		addr = mod_addr(PC + ADDR + i);
		ARENA[addr] = bytes[i];
		i++;
	}
}

void copy_carriage(t_env *vm, t_process *pointer, int addr)
{
	t_process *copy;

	copy = (t_process *)ft_memalloc(sizeof(t_process));
	ft_memcpy(copy->registry, pointer->registry, REG_NUMBER * sizeof(int32_t));
	copy->carry = pointer->carry;
	copy->last_live_cycle = pointer->last_live_cycle;
	copy->pc = addr;
	copy->is_ded = false;
	copy->step = 0;
	copy->cycles_left = 0;
	to_process_list(&pointer, copy, vm);
}