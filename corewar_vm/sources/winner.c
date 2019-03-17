#include "corewar_vm.h"

//TODO check if winner id is valid
void	announce_winner(t_env *vm, int winner_id)
{
	ft_printf("Contestant %d, ", winner_id);
	ft_printf("\"%s\", has won !\n", PLAYER[IDX(winner_id)]->name);
}