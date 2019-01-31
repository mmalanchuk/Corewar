/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13:41:33 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/08 13:41:43 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_helpers.h"
#include "ft_string_from_num.h"
#include "libft.h"
#include "ft_handle_specifier.h"
#include <stdlib.h>

char	*ft_length_l_signed_int(va_list ap, t_format_specifier *sp)
{
	long a;
	char *res;

	a = va_arg(ap, long);
	res = ft_string_from_num_signed((intmax_t)a, sp);
	return (res);
}

char	*ft_length_l_unsigned_int(va_list ap, t_format_specifier *sp)
{
	unsigned long	a;
	char			*res;
	char			c;

	c = sp->specifier;
	a = va_arg(ap, unsigned long);
	if (c == 'p')
	{
		sp->append_string = ft_strdup("0x");
		c = 'x';
	}
	res = ft_string_from_num_unsigned((uintmax_t)a, c, sp);
	return (res);
}

char	*ft_length_l_char(va_list ap, t_format_specifier *sp)
{
	wchar_t a;

	a = va_arg(ap, wchar_t);
	sp->wide_string = (wchar_t *)malloc(sizeof(wchar_t) + 1);
	sp->wide_string[0] = a;
	sp->wide_string[1] = '\0';
	if (sp->wide_string[0] == 0)
		sp->null_char++;
	else
		sp->wide_string_len = ft_wide_char_len(a);
	return (NULL);
}

char	*ft_length_l_string(va_list ap, t_format_specifier *sp)
{
	wchar_t	*a;
	int		i;
	int		len;
	int		wide_str_len;

	a = va_arg(ap, wchar_t *);
	if (!(len = 0) && !a)
	{
		(sp->precision >= 6 || sp->precision == -1) ?
		(sp->wide_string_len = 6) :
		(sp->wide_string_len = sp->precision);
		return (NULL);
	}
	wide_str_len = 0;
	while (!(i = 0) && a[len] && (wide_str_len + ft_wide_char_len(a[len]) <=
		sp->precision || sp->precision == -1) && ++len)
		wide_str_len += ft_wide_char_len(a[len - 1]);
	sp->wide_string = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	while (a[i] && i < len && ++i)
	{
		sp->wide_string[i - 1] = a[i - 1];
		sp->wide_string_len += ft_wide_char_len(a[i - 1]);
	}
	sp->wide_string[i] = '\0';
	return (NULL);
}

char	*ft_length_l(va_list ap, const char **s, int res,
	t_format_specifier *sp)
{
	char			*display;
	t_specifiers	**specifiers;
	int				i;

	specifiers = make_array_of_specifiers();
	(specifiers)[0]->func = ft_length_l_signed_int;
	specifiers[1]->func = ft_length_l_unsigned_int;
	specifiers[3]->func = ft_length_l_char;
	specifiers[4]->func = ft_length_l_string;
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
	free_specifiers(specifiers);
	free(specifiers);
	res = 0;
	return (display);
}
