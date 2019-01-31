/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operation_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:02:57 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/30 20:02:59 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				find_index(char *op_name)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (ft_strequ(g_op_tab[i].name, op_name))
			return (i);
		i++;
	}
	return (-1);
}

int				check_num(char *word)
{
	int i;

	i = -1;
	if (word[0] == '-')
		i++;
	while (++i < (int)ft_strlen(word))
		if (!ft_isdigit(word[i]))
			return (9);
	return (0);
}

int				check_label(char *word)
{
	unsigned int i;

	i = 0;
	while (i < ft_strlen(word))
	{
		if (!ft_strchr(LABEL_CHARS, word[i]))
			return (10);
		i++;
	}
	return (0);
}

int				get_length(char *word, int ind)
{
	if (!word)
		return (7);
	if (word[0] == 'r')
	{
		if (ft_atoi(&word[1]) <= 0 || ft_atoi(&word[1]) > REG_NUMBER)
			return (8);
		return ((check_num(&word[1]) == 9) ? 9 : 1);
	}
	if (word[0] == DIRECT_CHAR)
	{
		if (word[1] == LABEL_CHAR)
			return ((check_label(&word[2]) == 10) ? 10 :
					(!g_op_tab[ind].label * 2 + 2));
			return ((check_num(&word[1]) == 9) ? 9 :
					(!g_op_tab[ind].label * 2 + 2));
	}
	if (word[0] == LABEL_CHAR || ft_isdigit(word[0]) || word[0] == '-')
	{
		if (word[0] == LABEL_CHAR)
			return ((check_label(&word[1]) == 10) ? 10 : 2);
		return ((check_num(word)) == 9 ? 9 : 2);
	}
	return (5);
}

unsigned int	count_operation_size(t_argument **arguments, char *line,
	int row, t_address **head)
{
	unsigned int	res;
	unsigned int	ind;
	int				i;
	int				temp;

	ind = find_index(arguments[0]->arg);
	res = 1 + g_op_tab[ind].octal;
	i = 0;
	while (++i <= g_op_tab[ind].nb_arg)
	{
		(!arguments[i]) ? ft_handle_errors(make_error(row, (int)ft_strlen(line),
			4, head), &arguments) : 0;
		if (!arguments[i]->arg && i == g_op_tab[ind].nb_arg)
			ft_handle_errors(make_error(row, (int)ft_strlen(line), 6, head),
				&arguments);
		if (!(arguments[i]->arg[0]))
			ft_handle_errors(make_error(row, (int)ft_strlen(line), 23, head),
				&arguments);
		temp = get_length(arguments[i]->arg, ind);
		if (temp >= 5)
			ft_handle_errors(make_error(row, arguments[i]->col, temp, head),
				&arguments);
		res += temp;
	}
	return (res);
}
