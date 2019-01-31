#ifndef COREWAR_VM_VM_ERRORS_H
#define COREWAR_VM_VM_ERRORS_H

# define CANT_READ "Can't read source file %s\n"
# define INVALID_HEADER "Error: File %s has an invalid header"
# define INVALID_FILENAME "Error: Wrong filename: %s"
# define MEM_ALLOC_ERR "Memory allocation error"
# define READ_ERROR "Read error"
# define INCOMPLETE_PLAYER "The player is incomplete"
# define NO_NULL "Error: no null"
# define FLAG_ERR "Wrong flag argument %s\n"
# define END_ERR "Error: File %s has a code size that differ from what its header says\n"
# define CODE_SIZE_ERR "Code size if larger than CHAMP_MAX_SIZE"
# define ERR_MANY_PLAYERS "Too many players, see MAX_PLAYERS in op.h"
# define BAD_PLAYER_ID "Bad player id: %s\n"

#endif
