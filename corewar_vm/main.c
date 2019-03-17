#include "corewar_vm.h"

/**
 * g_cw_flags:
 * corewar options dispatcher
 * @@name - option name
 * @@f_ptr - function pointer that executes when a flag and its args are valid
 * to ADD new options append them in g_cw_flags definition below
 * and increment MAX_OPTIONS number
 */

t_flag_disp g_cw_flags[] = {
		{"n", &parse_champ_id},
		{"dump", &parse_dump_cycles},
};

void	corewar_usage()
{
	ft_putstr("Usage : ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] [...]\n");
	ft_putstr("-dump nbr_cycles\t: Dumps memory after nbr_cycles cycles then exits\n");
	ft_putstr("-n number\t\t\t: Sets the number of the next player\n");

	exit(EXIT_SUCCESS);
}

t_env	*init_vm()
{
	t_env	*vm;

	vm = (t_env *)ft_memalloc(sizeof(t_env));
	vm->flags.dump = -1;
	vm->flags.n = -1;
	vm->players_num = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->checks_count = 0;
	vm->lives_in_period = 0;
	vm->cursors = 0;
	return (vm);
}

int main(int argc, char **argv)
{
	t_env *vm;
	t_process *proclst;

	if (argc < 2)
		corewar_usage();
	else
	{
		vm = init_vm();
		parse_arguments(++argv, vm);
		proclst = get_processes(vm);
		play_corewar(vm, proclst);
		memory_free(vm);
	}
	ft_printf(GRN"Program ended successfully!\n");
	return (0);
}