#include "corewar_vm.h"


void	print_code(uint8_t *code, size_t size)
{
	int i ;

	i = 0;
	while (i < size)
	{
		ft_printf(MAG"%02x ", code[i]);
		i++;
	}
	ft_printf("\n"RESET);
}

void	print_players_list(t_champ *players)
{
	while (players)
	{
		ft_printf("Id : %15d\n", players->id);
		ft_printf("Name : %15s\n", players->name);
		ft_printf("Comment : %15s\n", players->comment);
		ft_printf("Code_size: %15d\n", players->code_size);
		ft_printf("Code :\n");
		print_code(players->code, players->code_size);
		ft_printf("Next : %15s\n", players->next ? players->next->name : NULL);
		players = players->next;
	}
}

void	print_players_array(t_env *vm)
{
	for (int i = 0; i < vm->players_num; ++i)
	{
		ft_printf("**************************************************************************************************************************************************************\n");
		ft_printf("Id : %15d\n", PLAYER[i]->id);
		ft_printf("Name : %15s\n", PLAYER[i]->name);
		ft_printf("Comment : %15s\n", PLAYER[i]->comment);
		ft_printf("Code_size: %15d\n", PLAYER[i]->code_size);
		ft_printf("Code :\n");
		print_code(PLAYER[i]->code, PLAYER[i]->code_size);
	}
	ft_printf("**************************************************************************************************************************************************************\n");
}
void	print_vm(t_env *vm)
{
	ft_printf("Printing VM....\n");
	ft_printf("Dump cycles: %d\n", vm->dump_cycles);
	ft_printf("Number of Champions: %u\n", vm->players_num);
	ft_printf("Printing players.....\n");
	print_players_array(vm);
}

void	print_register(int32_t reg[REG_NUMBER])
{
	ft_printf("Register: [");
	for (int i = 0; i < REG_NUMBER; ++i)
	{
		ft_printf("|%d|", reg[i]);
	}
	ft_printf("]\n");
}
void	print_processes_list(t_process *lst)
{
	while (lst)
	{
		ft_printf("******************************************************************************************************************************\n");
		ft_printf("Process id :%d\n", lst->id);
		print_register(lst->registry);
		ft_printf("PC : %d\n", lst->pc);
		ft_printf("Carry : %d\n", lst->carry);
		lst = lst->next;
	}
	ft_printf("******************************************************************************************************************************\n");
}

void print_arena(t_env *vm)
{
	int		id;
	int		step;
	int		bot;
	int		pc= 0;

	if (!vm)
		return ;
	id = vm->players_num - 1;
	char	*colors[] = {GRN, MAG, CYN, RED};
	step = MEM_SIZE / vm->players_num;
	bot = 0;
	while (pc < MEM_SIZE - 1)
	{
		if (pc % step == 0)
			ft_putstr(colors[id]);
		if (id >= 0 && pc == step * bot + PLAYER[id]->code_size)
		{
			ft_putstr(RESET);
			id--;
			bot++;
		}
		if (pc % 32 == 0)
			ft_putchar('\n');
		ft_printf("%02x ", ARENA[pc]);
		pc++;
	}
	ft_printf(RESET);
	ft_putchar('\n');
}