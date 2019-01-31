/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:06:31 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/08 14:06:32 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lengths.h"
#include <stdarg.h>
#include "ft_helpers.h"
#include "ft_printf.h"
#include <unistd.h>

t_format_specifier	*create_specifier(void)
{
	t_format_specifier *res;

	res = (t_format_specifier *)malloc(sizeof(t_format_specifier));
	res->left_justify = 0;
	res->preceed_sign = 0;
	res->insert_blanck_space = 0;
	res->has_hashtag = 0;
	res->pad_with_zeroes = 0;
	res->width = -1;
	res->precision = -1;
	res->func = NULL;
	res->null_char = 0;
	res->append_string = NULL;
	res->specifier = 0;
	res->wide_string = NULL;
	res->wide_string_len = 0;
	return (res);
}

int					ft_printf_check_format(va_list ap, const char **s, int res)
{
	t_format_specifier	*sp;
	char				*temp;

	sp = create_specifier();
	(*s)++;
	ft_handle_flags(ap, s, sp);
	temp = sp->func(ap, s, res, sp);
	(sp->null_char) ? res++ : 0;
	if (sp->precision != -1 && ft_strchr("diouxXb", sp->specifier))
		(sp->pad_with_zeroes = 0);
	res = ft_printf_write_string(temp, sp, res);
	(temp) ? free(temp) : 0;
	(sp->append_string) ? free(sp->append_string) : 0;
	(sp->wide_string) ? free(sp->wide_string) : 0;
	free(sp);
	return (res);
}

int					ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		res;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			res = ft_printf_check_format(ap, &format, res);
		else
		{
			ft_putchar(*format);
			res++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (res);
}
