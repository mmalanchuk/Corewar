/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:28:13 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/31 15:28:14 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "asm.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

unsigned int	start_asm(int fd_from, unsigned char **word)
{
	char			*line;
	t_address		*head;
	int				row;
	t_header		*header;
	unsigned int	res;

	line = NULL;
	head = NULL;
	row = 0;
	header = make_header(&row, fd_from);
	header->prog_size = 0;
	while (get_next_line(fd_from, &line))
	{
		row++;
		if (line && line[0] && line[0] != COMMENT_CHAR)
			header->prog_size += parse_line(line, &head, row);
		ft_strdel(&line);
	}
	if (!line)
		ft_handle_errors(make_error(row, 0, 15, &head), NULL);
	make_code(&head, header, word);
	res = header->prog_size;
	free(header);
	ft_strdel(&line);
	return (res);
}

int				main(int argc, const char *argv[])
{
	int				fd_from;
	char			*file_name;
	unsigned char	*word;
	int				fd_to;
	int				len;

	if (argc == 0)
		argv = NULL;
	word = ft_str_unsigned_new(0);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0 || read(fd_from, 0, 0) < 0)
		ft_printf("%s\n", strerror(errno));
	file_name = ft_strdup_until((char *)argv[1], '.');
	ft_strconcat(&file_name, ".cor", ft_strlen(file_name), 4);
	len = start_asm(fd_from, &word);
	close(fd_from);
	fd_to = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to < 0)
		ft_printf("%s\n", strerror(errno));
	write(fd_to, (char *)word, len + PROG_NAME_LENGTH + 12 + COMMENT_LENGTH);
	ft_str_unsigned_del(&word);
	close(fd_to);
	return (0);
}
