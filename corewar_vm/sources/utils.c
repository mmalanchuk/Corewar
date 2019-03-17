#include "corewar_vm.h"

//TODO parsing negative sign bytes . Artem says it's bullshit

/**
 * old function to read bytes for validation
 */

uint32_t read_uint32(t_file file)
{
	OCTET	buffer[4];
	ssize_t	bytes_read;
	int		i;

	i = 3;
	while (i >= 0)
	{
		if ((bytes_read = read(file.fd, &buffer[i], 1)) != 1)
			throw_error(bytes_read == -1 ? READ_ERROR : INCOMPLETE_PLAYER, file.name);
		i--;
	}
	return (*(uint32_t *)buffer);
}

int32_t mod_addr(int32_t addr)
{
	return (addr % MEM_SIZE);
}
/**
 * read_bytes()		read n bytes from src
 * @param src		source to read from (usually ARENA)
 * @param addr		current position pointer (PC) changes after read
 * @param n			number of bytes to read (1 || 2 || 4)
 * @return			returns casted value of read arguments
 */

uint32_t read_bytes(const OCTET *src, int addr, int n)
{
	OCTET *buffer;
	int i;

	addr = mod_addr(addr);
	//Temporary check of bad access
	if (addr > MEM_SIZE)
	{
		ft_dprintf(STDERR_FILENO, "addr > MEM_SIZE: addr(%d)\n", addr);
		exit(EXIT_FAILURE);
	}

	i = n;
	buffer = (OCTET *)ft_memalloc(sizeof(OCTET) * n + 1);
	while (--i >= 0)
	{
		buffer[i] = src[addr];
		addr++;
	}
	if (n == 2)
		return (*(uint16_t *)buffer);
	else if (n == 1)
		return (*(uint8_t *)buffer);
	else if (n == 4)
		return (*(uint32_t *)buffer);
	return (0);
}

