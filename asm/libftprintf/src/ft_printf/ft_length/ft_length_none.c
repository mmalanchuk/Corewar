/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_none.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13:49:31 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/08 13:49:32 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include "ft_helpers.h"
#include "ft_string_from_num.h"
#include "libft.h"
#include "ft_lengths.h"
#include "ft_handle_specifier.h"

char	*ft_length_none_char(va_list ap, t_format_specifier *sp)
{
	char *res;
	char c;

	c = va_arg(ap, int);
	res = ft_strnew(1);
	res[0] = c;
	res[1] = '\0';
	if (res[0] == 0)
		sp->null_char = 1;
	return (res);
}

char	*ft_length_none_string(va_list ap, t_format_specifier *sp)
{
	char *s;
	char *res;

	s = va_arg(ap, char *);
	res = NULL;
	if (!s)
		s = "(null)";
	if (sp->precision > -1 && sp->precision < (int)ft_strlen(s))
	{
		res = ft_strnew(sp->precision);
		res = ft_strncpy(res, s, sp->precision);
	}
	else
		res = ft_strdup(s);
	return (res);
}

char	*ft_length_none_nothing(va_list ap, t_format_specifier *sp)
{
	char *res;

	res = ft_strnew(1);
	if (ap)
		res[0] = sp->specifier;
	else
		res[0] = sp->specifier;
	return (res);
}

char	*ft_length_none(va_list ap, const char **s, int res,
	t_format_specifier *sp)
{
	char			*display;
	t_specifiers	**specifiers;
	int				i;

	specifiers = make_array_of_specifiers();
	display = NULL;
	sp->specifier = **s;
	i = 0;
	while (specifiers[i]->str[0] != '0' && !ft_strchr(specifiers[i]->str, **s))
		i++;
	if (**s == 'U' || **s == 'O')
		sp->specifier += 32;
	if (**s == '\0')
		i = 9;
	display = (specifiers)[i]->func(ap, sp);
	res = 0;
	free_specifiers(specifiers);
	free(specifiers);
	return (display);
}
