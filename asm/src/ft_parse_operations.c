/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:15:38 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/30 20:15:39 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	arg_possible(t_arg_type oper_arg, t_arg_type arg)
{
	if (arg == T_REG)
	{
		if (oper_arg == T_REG || oper_arg == (T_REG | T_DIR) ||
			oper_arg == (T_REG | T_IND) || oper_arg == (T_REG | T_DIR | T_IND))
			return (1);
		return (0);
	}
	if (arg == T_DIR)
	{
		if (oper_arg == T_DIR || oper_arg == (T_REG | T_DIR) ||
			oper_arg == (T_DIR | T_IND) || oper_arg == (T_REG | T_DIR | T_IND))
			return (1);
		return (0);
	}
	if (arg == T_IND)
	{
		if (oper_arg == T_IND || oper_arg == (T_IND | T_DIR) ||
			oper_arg == (T_REG | T_IND) || oper_arg == (T_REG | T_DIR | T_IND))
			return (1);
		return (0);
	}
	return (0);
}

int	turn_to_code(t_operation *op, t_argument **arguments, t_address *head,
	int *i)
{
	int position;

	op->code = ft_str_unsigned_new(op->length);
	op->code[0] = find_index(arguments[0]->arg);
	position = 1 + g_op_tab[op->code[0]].octal;
	while (arguments[++(*i)])
	{
		if (arguments[*i]->arg[0] == 'r' && ++position)
		{
			if (!arg_possible(g_op_tab[op->code[0]].args[*i - 1], T_REG))
				return (11);
			op->code[position - 1] = ft_atoi(&(arguments[*i]->arg[1]));
			add_label(op, T_REG);
			continue ;
		}
		if (arguments[*i]->arg[0] == DIRECT_CHAR &&
			!arg_possible(g_op_tab[op->code[0]].args[*i - 1], T_DIR))
			return (12);
		if ((ft_isdigit(arguments[*i]->arg[0]) || arguments[*i]->arg[0] ==
		LABEL_CHAR) && !arg_possible(g_op_tab[op->code[0]].args[*i - 1], T_IND))
			return (13);
		add_dir_on_indir(arguments[*i], &position, head, op);
	}
	op->code[0] += 1;
	return (0);
}

int	ft_parse_operations(t_argument **arguments, t_address **head,
	int row, char **line)
{
	t_operation		*temp_oper;
	unsigned int	length;
	t_address		*temp_addr;
	int				success;
	int				arg_position;

	temp_addr = NULL;
	arg_position = 0;
	length = count_operation_size(arguments, *line, row, head);
	temp_addr = *head;
	while (temp_addr->next)
		temp_addr = temp_addr->next;
	temp_addr->length += length;
	temp_oper = temp_addr->operations;
	while (temp_oper->next)
		temp_oper = temp_oper->next;
	temp_oper->length = length;
	success = turn_to_code(temp_oper, arguments, *head, &arg_position);
	if (success)
		ft_handle_errors(make_error(row, arguments[arg_position]->col, success,
				head), &arguments);
	return (length);
}
