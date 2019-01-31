/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_none_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:07:06 by adayrabe          #+#    #+#             */
/*   Updated: 2018/08/17 13:07:13 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_structs.h"
#include "ft_string_from_num.h"
#include "libft.h"

char	*ft_length_none_int(va_list ap, t_format_specifier *sp)
{
	char	*res;
	int		a;

	a = va_arg(ap, int);
	res = ft_string_from_num_signed((intmax_t)a, sp);
	return (res);
}

char	*ft_length_none_unsigned_int(va_list ap, t_format_specifier *sp)
{
	unsigned int	a;
	char			*res;
	char			c;

	a = va_arg(ap, unsigned int);
	c = sp->specifier;
	if (c == 'p')
	{
		sp->append_string = ft_strdup("0x");
		sp->has_hashtag = 1;
		c = 'x';
	}
	res = ft_string_from_num_unsigned((uintmax_t)a, c, sp);
	return (res);
}

char	*ft_length_none_floating_point(va_list ap, t_format_specifier *sp)
{
	char	*res;
	double	a;
	char	c;

	a = va_arg(ap, double);
	c = sp->specifier;
	if (sp->precision == -1)
		sp->precision = 6;
	res = ft_string_from_num_double((long double)a, c, sp);
	return (res);
}
