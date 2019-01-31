/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_from_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:03:23 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/08 14:03:24 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ft_helpers.h"
#include "libft.h"

char	*add_zeroes(char *s, int len)
{
	int i;

	i = 0;
	while (i < len && !ft_isalnum(s[i]))
	{
		s[i] = '0';
		i++;
	}
	return (s);
}

char	*ft_string_from_num_signed(intmax_t a, t_format_specifier *sp)
{
	uintmax_t	temp;
	char		*res;
	int			start_num;

	(a < 0) ? (sp->preceed_sign = 1) : 0;
	(a < 0) ? (temp = -1 * a) :
				(temp = a);
	start_num = 0;
	(a < 0) ? (res = ft_string_itoa_base(temp, '-', 10, sp)) :
	(res = ft_string_itoa_base(temp, '+', 10, sp));
	res = add_zeroes(res, sp->precision);
	(a < 0) ? sp->append_string = ft_strdup("-") : 0;
	if (a >= 0 && sp->preceed_sign)
		sp->append_string = ft_strdup("+");
	else if (sp->insert_blanck_space && a >= 0)
		sp->append_string = ft_strdup(" ");
	return (res);
}

char	*ft_string_from_num_unsigned(uintmax_t a, char c,
	t_format_specifier *sp)
{
	char *res;

	res = NULL;
	if (c == 'o' && sp->has_hashtag && a == 0 && sp->precision < 1)
		(sp->precision = 1);
	(c == 'u') ? (res = ft_string_itoa_base(a, '0', 10, sp)) : 0;
	(c == 'o') ? (res = ft_string_itoa_base(a, 'O', 8, sp)) : 0;
	(c == 'x') ? (res = ft_string_itoa_base(a, 'a', 16, sp)) : 0;
	(c == 'X') ? (res = ft_string_itoa_base(a, 'A', 16, sp)) : 0;
	(c == 'b') ? (res = ft_string_itoa_base(a, '0', 2, sp)) : 0;
	res = add_zeroes(res, sp->precision);
	(c == 'o' && sp->has_hashtag && a && sp->precision <
		(int)ft_strlen(res)) ? (sp->append_string = ft_strdup("0")) : 0;
	if ((c == 'x' || c == 'X') && sp->has_hashtag && a)
	{
		sp->append_string = ft_strdup("0x");
		(c == 'X') ? sp->append_string[1] = 'X' : 0;
	}
	return (res);
}

char	*ft_string_from_num_double(long double a, char c,
	t_format_specifier *sp)
{
	char		*res;
	intmax_t	exp;
	long double	temp;

	if (sp->has_hashtag && sp->precision == 0)
		sp->precision = 6;
	temp = a;
	exp = 0;
	if (c == 'e' || c == 'E')
	{
		while (((intmax_t)a >= 10 || (intmax_t)a <= -10 || (a < 1 && a > -1))
				&& ++exp)
			(a < 1 && a > -1) ? (a *= 10) : (a /= 10);
	}
	res = ft_string_ftoa(a, c, 10, sp);
	if ((c == 'e' || c == 'E') && (sp->precision = -1))
	{
		res[ft_strlen(res)] = c;
		(temp > 1) ? (res[ft_strlen(res)] = '+') :
					(res[ft_strlen(res)] = '-');
		(exp < 10) ? (res[ft_strlen(res)] = '0') : 0;
		res = ft_strcat(res, ft_string_from_num_unsigned(exp, 'u', sp));
	}
	return (res);
}
