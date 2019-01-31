/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dir_or_indir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:56:43 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/30 19:56:46 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_label(t_operation *op, t_arg_type arg)
{
	if (op->code[1] == 0)
		(arg == T_IND) ? (op->code[1] += 64 * 3) : (op->code[1] += 64 * arg);
	else if (op->code[1] % 64 == 0)
		(arg == T_IND) ? (op->code[1] += 16 * 3) : (op->code[1] += 16 * arg);
	else
		(arg == T_IND) ? (op->code[1] += 4 * 3) : (op->code[1] += 4 * arg);
}

void		add_number(unsigned int nbr, t_operation *op, int position,
	int length)
{
	while (length > 0)
	{
		op->code[position + length - 1] = nbr % 256;
		nbr /= 256;
		length--;
	}
}

t_argument	*add_arg(char *word, t_argument *arg, int length, int position)
{
	t_argument *res;

	res = make_arg(word, arg->row, arg->col, position);
	res->length = length;
	return (res);
}

void		add_bytes(t_address *head, int position, t_operation *op,
	int length)
{
	unsigned int	bytes;

	bytes = 0;
	while (head)
	{
		bytes += head->length;
		head = head->next;
	}
	add_number((unsigned int)(-1 * (int)(bytes - op->length)),
				op, position, length);
}

void		add_dir_on_indir(t_argument *arg, int *position, t_address *head,
	t_operation *op)
{
	int				length;
	char			*word;

	word = arg->arg;
	length = 2;
	if (g_op_tab[op->code[0]].octal)
		(word[0] == DIRECT_CHAR) ? add_label(op, T_DIR) : add_label(op, T_IND);
	if (word[0] == DIRECT_CHAR && ++word)
		length += !g_op_tab[op->code[0]].label * 2;
	if (ft_isdigit(word[0]) || word[0] == '-')
		add_number((unsigned int)(ft_atoi(word)), op, *position, length);
	else
	{
		while (head && !ft_strequ(head->name, &word[1]))
			head = head->next;
		if (!head)
			(!op->label1) ? (op->label1 = add_arg(&word[1], arg, length,
		*position)) : (op->label2 = add_arg(&word[1], arg, length, *position));
		else
			add_bytes(head, *position, op, length);
	}
	*position += length;
}
