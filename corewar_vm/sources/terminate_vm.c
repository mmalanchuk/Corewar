#include "corewar_vm.h"
#include <errno.h>

void throw_error(char *fmt, char *filename)
{
	ft_dprintf(STDERR_FILENO, fmt, filename);
	exit(EXIT_FAILURE);
}
