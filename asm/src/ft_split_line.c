/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:20:15 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/30 20:20:16 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*get_name(char *line, int *col)
{
	char	*name;
	int		temp;

	while (line && line[*col] && (line[*col] == ' ' || line[*col] == '\t' ||
		line[*col] == SEPARATOR_CHAR))
	{
		if (line[*col] == SEPARATOR_CHAR)
			return (NULL);
		(*col)++;
	}
	if (line && (line[*col] == COMMENT_CHAR || line[*col] == '\0'))
		return (NULL);
	temp = *col;
	name = NULL;
	while (line[*col] && line[*col] != ' ' && line[*col] != '\t' &&
		line[*col] != COMMENT_CHAR)
		(*col)++;
	if (line[*col] == COMMENT_CHAR || line[*col] == '\0')
		return (NULL);
	if (line[*col] == ' ')
		name = ft_strdup_until(&line[temp], ' ');
	if (line[*col] == '\t')
		name = ft_strdup_until(&line[temp], '\t');
	return (name);
}

t_argument	*make_arg(char *name, int row, int col, int position)
{
	t_argument *res;

	res = (t_argument *)malloc(sizeof(t_argument));
	res->arg = ft_strdup(name);
	res->row = row;
	res->col = col;
	res->position = position;
	return (res);
}

void		sep(char *line, int *col, char **res)
{
	while (line[*col] && (line[*col] == ' ' || line[*col] == '\t'))
		(*col)++;
	if (line[*col] != SEPARATOR_CHAR)
	{
		ft_strdel(res);
		*res = ft_strdup("");
	}
}

t_argument	*get_arg(char *line, char last_arg, int *col, int row)
{
	char		*res;
	int			temp;
	t_argument	*arg;

	while (line[*col] && (line[*col] == ' ' || line[*col] == '\t'))
		(*col)++;
	temp = *col;
	while (line[*col] && line[*col] != ' ' && line[*col] != '\t'
		&& line[*col] != COMMENT_CHAR && line[*col] != SEPARATOR_CHAR)
		(*col)++;
	if ((line[*col] == COMMENT_CHAR || !line[*col]) && !last_arg)
		return (NULL);
	res = ft_strdup_until(&line[temp], line[*col]);
	(line[*col] != SEPARATOR_CHAR && !last_arg) ? sep(line, col, &res) : 0;
	if (line[*col] != COMMENT_CHAR && line[*col] && last_arg)
	{
		while (line[*col] && (line[*col] == ' ' || line[*col] == '\t'))
			(*col)++;
		if (line[*col] != COMMENT_CHAR && line[*col] != '\0')
			ft_strdel(&res);
	}
	(*col)++;
	arg = make_arg(res, row, temp, 0);
	ft_strdel(&res);
	return (arg);
}

t_argument	**ft_split_line(char *line, int row, int col)
{
	char		*name;
	int			ind;
	int			i;
	t_argument	**res_arg;
	int			temp;

	name = get_name(line, &col);
	ind = find_index(name);
	temp = col;
	while (line[col] && (line[col] == ' ' || line[col] == '\t'))
		col++;
	if (ind == -1 || line[col] == SEPARATOR_CHAR || !line[col])
		return (NULL);
	res_arg = (t_argument **)malloc(sizeof(t_argument *) *
									(g_op_tab[ind].nb_arg + 2));
	res_arg[0] = make_arg(name, row, temp - (int)ft_strlen(name), 0);
	res_arg[g_op_tab[ind].nb_arg + 1] = NULL;
	ft_strdel(&name);
	i = 0;
	while (res_arg[i] && ++i <= g_op_tab[ind].nb_arg)
		res_arg[i] = get_arg(line, i == g_op_tab[ind].nb_arg, &col, row);
	while (i <= g_op_tab[ind].nb_arg && ++i)
		res_arg[i - 1] = NULL;
	return (res_arg);
}
