/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:55:05 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/31 14:55:06 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "asm.h"
#include <unistd.h>

void	add_unsigned_char(unsigned char **word, unsigned char c, int len)
{
	unsigned char *temp;

	temp = ft_str_unsigned_new(1);
	temp[0] = c;
	ft_str_unsigned_concat(word, temp, len, 1);
	ft_str_unsigned_del(&temp);
}

void	write_int(int *t, unsigned int num, unsigned char **word)
{
	int				i;
	unsigned char	temp;

	i = -1;
	while (++i < 4)
	{
		temp = num / ft_pow(256, 3 - i);
		temp = temp % ft_pow(256, i);
		add_unsigned_char(word, temp, *t);
		++(*t);
	}
}

void	write_header_to_file(t_header *header, unsigned char **word)
{
	int i;
	int t;

	if (!header)
		return ;
	t = 0;
	write_int(&t, header->magic, word);
	i = -1;
	while (++i <= PROG_NAME_LENGTH && header->prog_name[i] && ++t)
		add_unsigned_char(word, (unsigned char)header->prog_name[i], t - 1);
	while (++i <= PROG_NAME_LENGTH && ++t)
		add_unsigned_char(word, 0, t);
	write_int(&t, 0, word);
	write_int(&t, header->prog_size, word);
	i = -1;
	while (++i <= COMMENT_LENGTH && header->comment[i] && ++t)
		add_unsigned_char(word, header->comment[i], t - 1);
	while (++i <= COMMENT_LENGTH && ++t)
		add_unsigned_char(word, 0, t);
	write_int(&t, 0, word);
}

void	add_label_code(t_address **head, t_operation *op, t_argument *label)
{
	t_address		*temp;
	int				temp_bytes;
	t_operation		*temp_op;
	unsigned int	bytes;

	temp = *head;
	bytes = 0;
	while (temp)
	{
		if (ft_strequ(label->arg, temp->name))
			break ;
		bytes += temp->length;
		temp = temp->next;
	}
	if (!temp)
		ft_handle_errors(make_error(label->row, label->col, 22, head), NULL);
	temp_bytes = (*head)->length;
	temp_op = op;
	while (temp_op)
	{
		temp_bytes -= temp_op->length;
		temp_op = temp_op->next;
	}
	add_number((unsigned int)(bytes - temp_bytes), op,
		label->position, label->length);
}

void	make_code(t_address **head, t_header *header, unsigned char **word)
{
	t_operation		*temp;
	t_address		*temp_addr;
	unsigned int	i;
	int				len;

	write_header_to_file(header, word);
	len = PROG_NAME_LENGTH + 4 + 4 + 4 + COMMENT_LENGTH + 4;
	while (head && *head)
	{
		temp_addr = (*head)->next;
		temp = (*head)->operations;
		while ((i = -1) && temp)
		{
			(temp->label1) ? add_label_code(head, temp, temp->label1) : 0;
			(temp->label2) ? add_label_code(head, temp, temp->label2) : 0;
			ft_str_unsigned_concat(word, temp->code, len, temp->length);
			len += temp->length;
			temp = temp->next;
		}
		free_operations(&(*head)->operations);
		ft_strdel(&(*head)->name);
		free(*head);
		*head = temp_addr;
	}
}
