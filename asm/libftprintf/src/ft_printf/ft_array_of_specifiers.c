/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_of_specifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:34:05 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/04 17:34:11 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lengths.h"
#include "ft_handle_specifier.h"

void			assign_string_and_function(t_specifiers **sp, char *str,
	char *(*func)(va_list ap, t_format_specifier *sp))
{
	(*sp)->str = ft_strdup(str);
	(*sp)->func = func;
}

void			free_specifiers(t_specifiers **sp)
{
	int i;

	i = 0;
	while (i < 10)
	{
		free(sp[i]->str);
		free(sp[i]);
		i++;
	}
}

t_specifiers	**make_array_of_specifiers(void)
{
	t_specifiers	**r;
	int				i;

	r = (t_specifiers **)malloc(10 * sizeof(t_specifiers *));
	i = 0;
	while (i < 10 && ++i)
		r[i - 1] = (t_specifiers *)malloc(sizeof(t_specifiers));
	assign_string_and_function(&r[0], "di", ft_length_none_int);
	assign_string_and_function(&r[1], "uoxXb", ft_length_none_unsigned_int);
	assign_string_and_function(&r[2], "fFeEgGaA",
		ft_length_none_floating_point);
	assign_string_and_function(&r[3], "c", ft_length_none_char);
	assign_string_and_function(&r[4], "s", ft_length_none_string);
	assign_string_and_function(&r[5], "D", ft_length_l_signed_int);
	assign_string_and_function(&r[6], "UOp", ft_length_l_unsigned_int);
	assign_string_and_function(&r[7], "C", ft_length_l_char);
	assign_string_and_function(&r[8], "S", ft_length_l_string);
	assign_string_and_function(&r[9], "0", ft_length_none_nothing);
	return (r);
}
