#ifndef COREWAR_VM_VM_ERRORS_H
#define COREWAR_VM_VM_ERRORS_H

# define CANT_READ "Can't read source file %s\n"
# define INVALID_HEADER "Error: File %s has an invalid header"
# define INVALID_FILENAME "Error: Wrong filename: %s"
# define MEM_ALLOC_ERR "Memory allocation error"
# define READ_ERROR "Read error"
# define INCOMPLETE_PLAYER "The player is incomplete"
# define NO_NULL "Error: no null"
# define FLAG_ERR_N "Predefined number of next player must be between 1 and total number of players!\n"
# define OPT_ERR "Illegal option: %s\n"
# define FLAG_ERR_DUMP "Number od cycles must be a strictly positive integer!\n"
# define FLAG_ARG_ERR "Specify a valid argument for %s option\n"
# define END_ERR "Error: File %s has a code size that differ from what its header says\n"
# define CODE_SIZE_ERR "Code size if larger than CHAMP_MAX_SIZE"
# define ERR_MANY_PLAYERS "Too many players, see MAX_PLAYERS in op.h"

#endif
