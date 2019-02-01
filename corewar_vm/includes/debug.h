#include "corewar_vm.h"

#define DEBUG

void	print_vm(t_env *vm);
void	print_players_list(t_champ *players);
void	print_players_array(t_env *vm);
void	print_code(uint8_t *code, size_t size);
void	print_processes_list(t_process *lst);
void	print_arena(t_env *vm);