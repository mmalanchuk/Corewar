#ifndef COREWAR_VM_H
# define COREWAR_VM_H

# include "libft.h"
# include "vm_errors.h"
# include "op.h"
# include <fcntl.h>
# define PLAYER (vm->players)
# define ARENA (vm->arena)
# define COR ".cor"
# define IDX(X) ((X) - 1)
# define PC (vm->pointer->pc)
# define STEP (vm->pointer->step)
# define ARG_TYPE (vm->pointer->arg_type)
# define REG (vm->pointer->registry)
# define ARG (vm->pointer->args)
# define CARRY (vm->pointer->carry)
# define OP (vm->pointer->op)
# define ADDR (vm->pointer->addr)

# define MAX_OPTIONS 2

/**
 * uint8_t/OCTET	is unsigned char
 * uint16_t			is unsigned short
 * uint32_t			is unsigned int
 */

typedef uint8_t BYTE;


typedef struct	s_player
{
	int				id;
	char			*name;
	char			*comment;
	size_t			code_size;
	unsigned char	*code;
	int				last_live_cycle;
	unsigned int	lives;
	struct s_player	*next;
}				t_champ;

/**
 * cycles left - delay before op execute
 * arg_len - length of arguments due to it coding octet
 * step - calculate operation step within its arguments coding octet etc
 */

typedef struct	s_process
{
	int32_t				registry[REG_NUMBER];
	int					pc;
	int					step;
	int					arg_len;
	int					addr;
	bool				carry;
	t_op				*op;
	t_arg_type			arg_type[MAX_ARGS_NUMBER];
	int32_t				args[MAX_ARGS_NUMBER];
	int					cycles_left;
	int					last_live_cycle;
	struct s_process	*next;
}				t_process;

typedef struct	s_cw_flags
{
	int	n;
	int	dump;
}				t_cw_flags;
/**
 * lives_num number of lives since last cycle_to_die
 */
typedef	struct
{
	uint8_t		arena[MEM_SIZE];
	t_cw_flags	flags;
	t_champ		*players[MAX_PLAYERS];
	unsigned	players_num;
	int			cycles_to_die;
	int			checks_count;
	int			cycles_after_check;
	int			last_alive;
	size_t		lives_in_period;
	int			cycle;
	int			cursors;
	t_process	*pointer;
}				t_env;

typedef struct
{
	char	*name;
	int		fd;
	bool	open;
}	t_file;

typedef struct	s_flags_disp
{
	char	*name;
	void	(*f_ptr)(char***, t_cw_flags*);
}				t_flag_disp;

void		parse_arguments(char **argv, t_env *vm);
void		parse_player(t_env *vm, char *filename, t_champ **lst, int *id);

extern t_flag_disp	g_cw_flags[];
void		parse_champ_id(char ***argv, t_cw_flags *flags);
void		parse_dump_cycles(char ***argv, t_cw_flags *flags);



bool		is_cor_file(char *filename);
bool		valid_header(t_file file);
bool		is_player_id(t_env *vm, int id);
bool		is_registry_id(int id);


void		corewar_usage();
void 		play_corewar(t_env *vm);
void		memory_free(t_env *vm);
void		throw_error(char *fmt, char *filename);


uint32_t	read_uint32(t_file file);
uint32_t	read_bytes(const BYTE *src, int addr, int n);
void		write_to_arena(t_env *vm, int32_t value);
bool		get_arg_types(t_env *vm);
void		get_args(t_env *vm, bool return_ind_addr);



void copy_carriage(t_env *vm, int addr);

t_process	*get_processes(t_env *vm);
/*
 * main cycle
 */
void	run_vm_cycle(t_env *vm);

bool check_alive(t_env *vm);
void get_current_op(t_env *vm);


void	introduce_contestants(t_env *vm);
void	announce_winner(t_env *vm, int winner_id);

int32_t	mod_addr(int32_t addr);
void to_process_list(t_process **lst, t_process *proc, t_env *vm);
#endif