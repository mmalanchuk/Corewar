#include "corewar_vm.h"

void	free_players(t_env *vm)
{
	int		i;

	i = 0;
	while (i < vm->players_num)
	{
		PLAYER[i] = PLAYER[i];
		ft_strdel(&PLAYER[i]->name);
		ft_strdel(&PLAYER[i]->comment);
		ft_memdel((void **)&PLAYER[i]->code);
		ft_memdel((void **)&PLAYER[i]);
		i++;
	}
}
void	memory_free(t_env *vm)
{
	free_players(vm);
	free(vm);
}