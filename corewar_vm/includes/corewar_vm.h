#ifndef COREWAR_VM_H
# define COREWAR_VM_H

# include "libft.h"
# include "vm_errors.h"
# include "op.h"
# include <fcntl.h>
# define PLAYER (vm->players)
# define ARENA (vm->arena)
# define COR ".cor"
# define IDX(X) (X - 1)
# define PC (pointer->pc)
# define ARG_TYPE (pointer->arg_type)
# define REG (pointer->registry)
# define ARG (pointer->args)
# define CARRY (pointer->carry)
# define OP (pointer->op)
# define ADDR (pointer->addr)
# define STEP (pointer->pc_step)
# define CYCLES (pointer->op->exec_cycles)

# define MAX_OPTIONS 2

/**
 * uint8_t/OCTET	is unsigned char
 * uint16_t			is unsigned short
 * uint32_t			is unsigned int
 */

typedef uint8_t OCTET;


typedef struct	s_player
{
	int				id;
	char			*name;
	char			*comment;
	size_t			code_size;
	unsigned char	*code;
	int				last_live_cycles;
	unsigned int	lives;
	struct s_player	*next;
}				t_champ;

typedef struct	s_process
{
	int					id;
	int32_t				registry[REG_NUMBER];
	int					pc;
	int					pc_step;
	int					addr;
	bool				carry;
	t_op				op;
	t_arg_type			arg_type[MAX_ARGS_NUMBER];
	int32_t				args[MAX_ARGS_NUMBER];
	int					cycles_left;
	int					last_live_cycles;
	struct s_process	*next;
}				t_process;

typedef struct	s_cw_flags
{
	int	n;
	int	dump;
}				t_cw_flags;

typedef	struct
{
	uint8_t		arena[MEM_SIZE];
	t_cw_flags	flags;
//	int			dump_cycles;
	t_champ		*players[MAX_PLAYERS];
	unsigned	players_num;
	int			cycles_to_die;
	int			checks_count;
	int			last_alive_id;
	int			cycle;
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
void 		play_corewar(t_env *vm, t_process *pointer);
void		memory_free(t_env *vm);
void		throw_error(char *fmt, char *filename);


uint32_t	read_uint32(t_file file);
uint32_t	read_bytes(const OCTET *src, int pos, int n);
void		write_to_arena(t_env *vm, t_process *pointer, int32_t value);
bool		set_arg_types(t_env *vm, t_process *pointer);
void		get_args(t_env *vm, t_process *pointer, bool return_ind_addr);


void	step_over(t_process *pointer);

void	copy_process(t_env *vm, t_process *pointer, int where);

t_process	*get_processes(t_env *vm);

#endif