/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:54:09 by adayrabe          #+#    #+#             */
/*   Updated: 2018/08/17 13:54:12 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lengths.h"

void		assign_func_to_char(t_length **res, char c, char *(*func)
	(va_list ap, const char **s, int res, t_format_specifier *sp))
{
	(*res)->c = c;
	(*res)->func = func;
}

t_length	**make_array_of_lengths(void)
{
	t_length	**r;
	int			i;

	r = (t_length **)malloc(7 * sizeof(t_length *));
	i = 0;
	while (i < 7 && ++i)
		r[i - 1] = (t_length *)malloc(sizeof(t_length));
	assign_func_to_char(&r[0], 'h', ft_length_h);
	assign_func_to_char(&r[1], 'l', ft_length_l);
	assign_func_to_char(&r[2], 'z', ft_length_z);
	assign_func_to_char(&r[3], 'j', ft_length_j);
	assign_func_to_char(&r[4], '0', ft_length_none);
	assign_func_to_char(&r[5], 't', ft_length_hh);
	assign_func_to_char(&r[6], 'y', ft_length_ll);
	return (r);
}

void		ft_free_modifier(t_length **length_modifier)
{
	int i;

	i = 0;
	while (i < 7)
	{
		free(length_modifier[i]);
		length_modifier[i] = NULL;
		i++;
	}
}

void		ft_printf_add_length(const char **s, t_format_specifier *sp)
{
	t_length	**length_modifier;
	int			i;
	int			j;

	length_modifier = make_array_of_lengths();
	i = 0;
	j = 0;
	while (length_modifier[i]->c != **s && length_modifier[i]->c != '0')
		i++;
	while (sp->func && sp->func != length_modifier[j]->func)
		j++;
	(length_modifier[i]->c != '0') ? (*s)++ : 0;
	if (sp->func == ft_length_h && (i == 0))
		sp->func = ft_length_hh;
	else if (sp->func == ft_length_l && (i == 1 && (j > 4 || j <= i)))
		sp->func = ft_length_ll;
	else if ((j > 4 || j <= i))
		sp->func = length_modifier[i]->func;
	ft_free_modifier(length_modifier);
	free(length_modifier);
}
