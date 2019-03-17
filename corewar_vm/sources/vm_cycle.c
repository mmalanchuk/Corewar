#include <debug.h>
#include "corewar_vm.h"

/*
 * Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
 * А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.
 */

bool need_check(t_env *vm)
{
	return (vm->cycles_to_die <= 0 || vm->cycles_to_die == vm->cycles_after_check);
}

/*
 * Во время каждого цикла происходит просмотр всего списка кареток.
 * И в зависимости от состояния каждой из них выполняются определенные действия — устанавливается новый код операции,
 * уменьшается количество циклов до исполнения или же выполняется сама операция, на которой стоит каретка.
 */

/**
 * before cycle sets initial ops to execute
 */

void	set_carriage_init_ops(t_env *vm, t_process *pointer)
{
	while (pointer)
	{
		get_current_op(vm, pointer);
		pointer = pointer->next;
	}
}

void	refresh_carriage(t_process *pointer)
{
	OP = NULL;
	ADDR = 0;
	ft_bzero(ARG_TYPE, MAX_ARGS_NUMBER);
	ft_bzero(ARG, sizeof(ARG));
}

void get_current_op(t_env *vm, t_process *pointer)
{
	int op_code;

	op_code = read_bytes(ARENA, PC, OP_SIZE);
	if (op_code >= 1 && op_code <= 16)
		OP = &op_tab[IDX(op_code)];
	pointer->cycles_left = OP ? OP->cycles_to_exec : 0;
}

void exec_carriage_ops(t_env *vm, t_process *pointer)
{
	vm->cycle++;
	vm->cycles_after_check++;
	while (pointer)
	{
		if (pointer->is_ded == false)
		{
			if (pointer->cycles_left > 0)
				pointer->cycles_left--;
			if (pointer->cycles_left == 0)
			{
				STEP = OP_SIZE;
				if (OP)
					OP->f_ptr(vm, pointer);
				PC += STEP;
				refresh_carriage(pointer);
				get_current_op(vm, pointer);
			}
		}
		pointer = pointer->next;
	}

}

void	print_dump(t_env *vm)
{
	print_arena(vm);
	memory_free(vm);
	exit(EXIT_SUCCESS);
}

/*
 * Если же количество выполненных операций live меньше установленного лимита, то виртуальная машина просто запоминает, что была выполнена проверка.

	Если MAX_CHECKS проверок спустя значение cycles_to_die не изменится, то оно будет принудительно уменьшено на значение CYCLE_DELTA.
 */

//TODO check if cycle runs when cycle to die <= 0
//TODO cycle ends up earlier than it should

void run_vm_cycle(t_env *vm, t_process *pointer)
{
	bool	one_alive;

	one_alive = true;
	set_carriage_init_ops(vm, pointer);
	vm->last_alive = FT_ABS(REG[0]);
	vm->cycles_after_check = 0;
	while (one_alive)
	{
		if (vm->cycle == vm->flags.dump)
			print_dump(vm);
		exec_carriage_ops(vm, pointer);
		if (need_check(vm))
			one_alive = check_alive(vm, pointer);
	}

	print_arena(vm);

	ft_printf("\nCorewar ended at %d cycle! Cycle_to_die: %d\n\n", vm->cycle, vm->cycles_to_die);

	announce_winner(vm, vm->last_alive);
}