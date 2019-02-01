/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:51:06 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/31 14:51:08 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "asm.h"
#include <unistd.h>

void	make_address(t_address **head, char *name)
{
	t_address *temp;

	if (!(*head))
	{
		*head = (t_address *)malloc(sizeof(t_address));
		temp = *head;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = (t_address *)malloc(sizeof(t_address));
		temp = temp->next;
	}
	temp->name = ft_strdup(name);
	temp->next = NULL;
	temp->operations = NULL;
	temp->length = 0;
}

t_error	*make_error(int line, int col, int num, t_address **head)
{
	t_error *res;

	res = (t_error *)malloc(sizeof(t_error));
	res->line = line;
	res->column = col;
	res->num = num;
	res->head = head;
	return (res);
}

char	*find_name(char *str, int *col)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t') && ++i)
		(*col)++;
	len = 0;
	while (str[i + len] && str[i + len] != LABEL_CHAR && str[i + len] != ' '
			&& str[i + len] != '\t' && ft_strchr(LABEL_CHARS, str[i + len]))
		len++;
	if (str[i + len] == ' ' || str[i + len] == '\t' || !str[i + len])
		return (NULL);
	if (!ft_strchr(LABEL_CHARS, str[i + len] && str[i + len] != LABEL_CHAR))
		return (ft_strdup(""));
	res = ft_strnew(len);
	(*col) += len;
	len = 0;
	while (str && str[i] != LABEL_CHAR)
	{
		res[len++] = str[i];
		i++;
	}
	(*col)++;
	return (res);
}

int		check_operator(int row, t_address **head, char *line, int col)
{
	int i;

	i = col - 1;
	while (line[++i] && (line[i] == ' ' || line[i] == '\t' ||
											line[i] == SEPARATOR_CHAR))
		if (line[i] == SEPARATOR_CHAR)
			ft_handle_errors(make_error(row, col, 16, head), NULL);
	if (line[i] == COMMENT_CHAR || line[i] == '\0')
		return (0);
	while (line[i] && line[i] != ' ' && line[i] != '\t' &&
												line[i] != SEPARATOR_CHAR)
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == SEPARATOR_CHAR)
		ft_handle_errors(make_error(row, i, 1, head), NULL);
	else if (line[i])
		ft_handle_errors(make_error(row, col, 0, head), NULL);
	else
		ft_handle_errors(make_error(row, i, 2, head), NULL);
	return (0);
}

int		parse_line(char *line, t_address **head, int row)
{
	char		*name;
	t_argument	**arguments;
	int			res;
	int			col;

	col = 0;
	name = find_name(line, &col);
	if (name && !name[0])
		ft_handle_errors(make_error(row, col, 3, head), NULL);
	(name || !(*head)) ? make_address(head, name) : 0;
	add_operation(*head, row);
	ft_strdel(&name);
	arguments = ft_split_line(line, row, col);
	if (!arguments && !check_operator(row, head, line, col))
		return (0);
	res = ft_parse_operations(arguments, head, row, &line);
	col = -1;
	while (arguments && arguments[++col])
	{
		ft_strdel(&(arguments[col]->arg));
		free(arguments[col]);
		arguments[col] = NULL;
	}
	free(arguments);
	return (res);
}
