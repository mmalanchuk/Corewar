#include "corewar_vm.h"

bool	is_cor_file(char *filename)
{
	return (bool)(ft_strlen(filename) > ft_strlen(COR)
	&& ft_strequ(ft_strrchr(filename, '.'), COR));
}

bool	valid_header(t_file file)
{
	return (read_uint32(file) == COREWAR_EXEC_MAGIC);
}
