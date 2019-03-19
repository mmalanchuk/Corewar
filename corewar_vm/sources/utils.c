#include "corewar_vm.h"

/**
 * old function to read bytes for validation
 */

//TODO remove if redundant function read_int32

uint32_t read_uint32(t_file file)
{
	BYTE	buffer[4];
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
 * @param addr		current position vm->pointer (PC) changes after read
 * @param n			number of bytes to read (1 || 2 || 4)
 * @return			returns casted value of read arguments
 */

uint32_t read_bytes(const BYTE *src, int addr, int n)
{
	BYTE	*buffer;
	uint32_t	res;
	int			i;

	addr = mod_addr(addr);
	buffer = (BYTE *)ft_memalloc(sizeof(BYTE) * n + 1);
	i = n;
	while (--i >= 0)
	{
		buffer[i] = src[addr];
		addr++;
	}
	res = 0;
	if (n == 2)
		res = *(uint16_t *)buffer;
	else if (n == 1)
		res = *(uint8_t *)buffer;
	else if (n == 4)
		res = *(uint32_t *)buffer;
	ft_memdel((void **)&buffer);
	return (res);
}

