#include "corewar_vm.h"

void	introduce_contestants(t_env *vm)
{
	int i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm->players_num)
	{
		ft_printf("* Player %d, ", i + 1);
		ft_printf("weighing %d bytes, ", PLAYER[i]->code_size);
		ft_printf("\"%s\" ", PLAYER[i]->name);
		ft_printf("(\"%s\") !\n", PLAYER[i]->comment);
		i++;
	}
}