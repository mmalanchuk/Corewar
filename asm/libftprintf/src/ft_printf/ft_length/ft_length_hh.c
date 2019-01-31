/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_hh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13:36:32 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/08 13:36:34 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_helpers.h"
#include "libft.h"
#include <unistd.h>
#include "ft_string_from_num.h"
#include "ft_lengths.h"
#include "ft_handle_specifier.h"

char	*ft_length_hh_signed_int(va_list ap, t_format_specifier *sp)
{
	char	a;
	char	*res;

	a = va_arg(ap, int);
	res = ft_string_from_num_signed((intmax_t)a, sp);
	return (res);
}

char	*ft_length_hh_unsigned_int(va_list ap, t_format_specifier *sp)
{
	unsigned char	a;
	char			*res;
	char			c;

	a = va_arg(ap, unsigned int);
	c = sp->specifier;
	res = ft_string_from_num_unsigned((uintmax_t)a, c, sp);
	return (res);
}

void	ft_length_hh_char_pointer(va_list ap)
{
	char *c;
	char *res;

	c = va_arg(ap, char *);
	res = va_arg(ap, char *);
}

char	*ft_length_hh(va_list ap, const char **s, int res,
	t_format_specifier *sp)
{
	char			*display;
	t_specifiers	**specifiers;
	int				i;

	sp->specifier = **s;
	specifiers = make_array_of_specifiers();
	(specifiers)[0]->func = ft_length_hh_signed_int;
	specifiers[1]->func = ft_length_hh_unsigned_int;
	display = NULL;
	i = 0;
	while (specifiers[i]->str[0] != '0' &&
		ft_strchr(specifiers[i]->str, **s) == 0)
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
