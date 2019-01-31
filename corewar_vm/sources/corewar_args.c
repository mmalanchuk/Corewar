#include "corewar_vm.h"
#include "debug.h"


static bool	digits_in_str(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

//TODO add check if -n arg is larger than players number
int		get_next_player_id(char *argv)
{
	int id;

	if (!digits_in_str(argv))
		throw_error(FLAG_ERR, argv);
	id = ft_atoi(argv);
	if (id < 1 || id > MAX_PLAYERS)
		throw_error(FLAG_ERR, argv);
	return (id);
}

int get_dump_cycles(char *argv)
{
	int nbr_cycles;

	if (!digits_in_str(argv))
		throw_error(FLAG_ERR, argv);
	nbr_cycles = ft_atoi(argv);
	//TODO is there MAX_NUMBER_OF_CYCLES ?
	if (nbr_cycles < 0)
		throw_error(FLAG_ERR, argv);
	return (nbr_cycles);
}

void 	set_defined_ids(t_env *vm, t_champ *lst)
{
	while (lst)
	{
		if (lst->id != -1)
		{
			if (lst->id > vm->players_num || PLAYER[lst->id - 1] != 0)
				throw_error(BAD_PLAYER_ID, lst->name);
			else
				PLAYER[lst->id - 1] = lst;
		}
		lst = lst->next;
	}
}

void	set_players_to_vm(t_env *vm, t_champ *lst)
{
	int i;

	set_defined_ids(vm, lst);
	i = 0;
	while (lst)
	{
		if (lst->id == -1)
		{
			while (PLAYER[i] != 0 && i < vm->players_num)
				i++;
			PLAYER[i] = lst;
			PLAYER[i]->id = i + 1;
		}
		lst = lst->next;
	}
}

void parse_arguments(int argc, char **argv, t_env *vm)
{
	int		i;
	int		id;
	t_champ *lst;

	lst = NULL;
	i = 1;
	id = -1;
	while (i < argc)
	{
		if (is_cor_file(argv[i]))
			parse_player(vm, argv[i], &lst, &id);
		else if (ft_strequ("-n", argv[i]) && is_cor_file(argv[i + 2]) && ++i)
			id = get_next_player_id(argv[i]);
		else if (ft_strequ("-dump", argv[i]) && i + 1 < argc && ++i)
			vm->dump_cycles = get_dump_cycles(argv[i]);
		else
			corewar_usage();
		i++;
	}
	set_players_to_vm(vm, lst);
#ifdef DEBUG
	print_vm(vm);
#endif
}
