#include "corewar_vm.h"
#include "debug.h"

void 	set_defined_ids(t_env *vm, t_champ *lst)
{
	while (lst)
	{
		if (lst->id != -1)
		{
			if (lst->id > vm->players_num || PLAYER[lst->id - 1] != 0)
				throw_error(FLAG_ERR_N, NULL);
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

static void	find_flag(char ***argv, t_cw_flags *flags)
{
	int i;

	i = 0;
	while (i < MAX_OPTIONS)
	{
		if (ft_strequ(**argv, g_cw_flags[i].name))
			return (g_cw_flags[i].f_ptr(argv, flags));
		i++;
	}
	throw_error(OPT_ERR, **argv);
}

void	parse_arguments(char **argv, t_env *vm)
{
	t_champ *lst;

	lst = NULL;
	++argv;
	while (*argv)
	{
		if (is_cor_file(*argv))
			parse_player(vm, *argv, &lst, &vm->flags.n);
		else if (**argv == '-' && ++(*argv))
			find_flag(&(argv), &vm->flags);
		else
			corewar_usage();
		argv++;
	}
	set_players_to_vm(vm, lst);
#ifdef DEBUG
	print_vm(vm);
#endif
}
