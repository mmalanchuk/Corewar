/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:55:07 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/04 17:55:10 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_lengths.h"
#include <stdarg.h>
#include <stdint.h>
#include "ft_string_from_num.h"

int			ft_len(size_t a, int base, t_format_specifier *sp)
{
	int res;

	if (a == 0)
		return (sp->precision != 0);
	res = 0;
	while (a)
	{
		res++;
		a = a / base;
	}
	return (res);
}

int			ft_wide_char_len(unsigned int a)
{
	if (!(a / 128) && MB_CUR_MAX >= 1)
		return (1);
	if (!(a / 2048) && MB_CUR_MAX >= 2)
		return (2);
	if (!(a / 65536) && MB_CUR_MAX >= 3)
		return (3);
	return (4);
}

char		*ft_string_itoa_base(size_t a, char c, int base,
							t_format_specifier *sp)
{
	char	*res;
	int		len;

	len = ft_len(a, base, sp);
	((sp->precision > len)) ? (len = sp->precision) : 0;
	res = ft_strnew(len);
	if (!a && sp->precision != 0)
		res[len - 1] = '0';
	while (a)
	{
		if (a % base >= 10)
			res[--len] = (a % base) - 10 + c;
		else
			res[--len] = a % base + '0';
		a = a / base;
	}
	return (res);
}

long double	ft_round_double(long double a, int precision)
{
	long double	temp;
	int			i;

	i = 0;
	temp = 0.5;
	while (i < precision)
	{
		temp /= 10.0;
		i++;
	}
	(a > 0) ? (a += temp) : (a -= temp);
	return (a);
}

char		*ft_string_ftoa(long double a, char c, int base,
	t_format_specifier *sp)
{
	char		*res;
	char		*temp;
	int			len;
	long double	t;
	int			x;

	a = ft_round_double(a, sp->precision);
	len = ft_len(((a > 0) * 2 - 1) * (ssize_t)a, base, sp) + 3 * (c == 'e');
	(sp->precision != 0 || sp->has_hashtag) ? (len += sp->precision + 1) : 0;
	res = ft_strnew(len + 1);
	x = sp->precision;
	sp->precision = 1;
	temp = ft_string_from_num_signed((ssize_t)a, sp);
	sp->precision = x;
	res = ft_strcat(res, temp);
	(t = a - (ssize_t)a);
	if (!(x = 0) && (sp->precision || sp->has_hashtag))
		res[ft_strlen(temp)] = '.';
	while (x < sp->precision && ++x)
	{
		res[ft_strlen(temp) + x] = '0' + ((a > 0) * 2 - 1) * (int)(t * 10);
		t = t * 10 - (int)(t * 10);
	}
	free(temp);
	return (res);
}
