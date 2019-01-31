#include "corewar_vm.h"

//TODO BIG ENDIAN research
//TODO parsing negative sign bytes

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

/**
 * read_bytes()		read n bytes from src
 * @param src		source to read from (usually ARENA)
 * @param pos		current position pointer (PC) changes after read
 * @param n			number of bytes to read (1 || 2 || 4)
 * @return			returns casted value of read arguments
 */

uint32_t read_bytes(const OCTET *src, int pos, int n)
{
	OCTET *buffer;
	int i;

	i = n;
	buffer = (OCTET *)ft_memalloc(sizeof(OCTET) * n + 1);
	while (--i >= 0)
	{
		buffer[i] = src[pos];
		pos++;
	}
	if (n == 2)
		return (*(uint16_t *)buffer);
	else if (n == 1)
		return (*(uint8_t *)buffer);
	else if(n == 4)
		return (*(uint32_t *)buffer);
	return (0);
}

