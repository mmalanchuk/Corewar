/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:21:46 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

/**
** All sizes are in bytes.
** It is assumed that an int is 32 bits. Is it true at home?
*/

#include <stdint.h>
#include <stdbool.h>

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE

#define OP_SIZE					1
#define REG_IDX_SIZE			1

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

struct	s_process;
struct s_env;
typedef struct s_op
{
	char		*name;
	uint8_t		arg_num;
	t_arg_type	arg_type[MAX_ARGS_NUMBER];
	uint8_t		op_code;
	uint32_t	cycles_to_exec;
	char		*description;
	bool		change_carry;
	bool		arg_codes;
	bool		t_dir_size_diff;
	bool		idx_mod;
	void		(*f_ptr)(struct s_env *vm, struct s_process *pointer);
}				t_op;

extern t_op	op_tab[16];
void	op_add();
void	op_aff();
void	op_and();
void	op_fork();
void	op_ld();
void	op_ldi();
void	op_lfork();
void	op_live();
void	op_lld();
void	op_lldi();
void	op_or();
void	op_xor();
void	op_st();
void	op_sti();
void	op_sub();
void	op_zjmp();