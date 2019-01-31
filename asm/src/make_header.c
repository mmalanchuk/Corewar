/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:39:03 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/31 14:39:05 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*get_until_quote(char *line, int *l, int col, int fd)
{
	char	*res;
	char	*temp;
	int		i;

	temp = ft_strdup(&line[col]);
	if (!ft_strchr(&line[col], '"'))
	{
		while (!ft_strchr(temp, '"') && ++(*l))
		{
			ft_strdel(&line);
			if (!get_next_line(fd, &line))
				ft_handle_errors(make_error(*l - 1, 0, 19, NULL), NULL);
			ft_strconcat(&temp, "\n", ft_strlen(temp), 1);
			ft_strconcat(&temp, line, ft_strlen(temp), ft_strlen(line));
			ft_strdel(&line);
		}
	}
	res = ft_strdup_until(temp, '"');
	i = (int)ft_strlen(res) + 1;
	while (temp[i] && (temp[i] == ' ' || temp[i] == '\t'))
		i++;
	(temp[i]) ? ft_handle_errors(make_error(*l, i, 18, NULL), NULL) : 0;
	ft_strdel(&line);
	ft_strdel(&temp);
	return (res);
}

char		*get_name_or_comment(char *line, int *l, char *name, int fd)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(name);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strnequ(&line[i], name, ft_strlen(name)))
		ft_handle_errors(make_error(*l, i, 17, NULL), NULL);
	i += len;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	(line[i] != '"') ? ft_handle_errors(make_error(*l, i, 18, NULL), NULL) : 0;
	return (get_until_quote(line, l, i + 1, fd));
}

char		contains_not_spaces(char *line)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == COMMENT_CHAR)
			return (0);
		if (line[i] != ' ' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

char		add_name_and_comment(t_header *header, int fd, int *l,
	char name_or_comment)
{
	char *line;
	char *temp;
	char res;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		(*l)++;
		if (contains_not_spaces(line))
			break ;
		ft_strdel(&line);
	}
	res = !ft_strstr(line, ".name") + 1;
	if (ft_strstr(line, ".name"))
		(name_or_comment != 1) ? (temp = get_name_or_comment(line, l, ".name",
			fd)) : ft_handle_errors(make_error(*l, 0, 20, NULL), NULL);
	else if (ft_strstr(line, ".comment"))
		(name_or_comment != 2) ? (temp = get_name_or_comment(line, l,
	".comment", fd)) : ft_handle_errors(make_error(*l, 0, 21, NULL), NULL);
	else
		ft_handle_errors(make_error(*line, 0, 17, NULL), NULL);
	(res == 1) ? ft_strcpy(header->prog_name, temp) :
									ft_strcpy(header->comment, temp);
	ft_strdel(&temp);
	return (res);
}

t_header	*make_header(int *l, int fd)
{
	t_header	*res;
	char		name;

	res = (t_header *)malloc(sizeof(t_header));
	res->magic = COREWAR_EXEC_MAGIC;
	name = add_name_and_comment(res, fd, l, 0);
	add_name_and_comment(res, fd, l, name);
	return (res);
}
