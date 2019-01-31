/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:48:38 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/08 14:48:41 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_parsers.h"
#include "ft_printf_printers.h"

static t_ft_printf	*init_handler(void)
{
	t_ft_printf *handler;

	handler = (t_ft_printf *)malloc(sizeof(t_ft_printf));
	handler->fd = -1;
	handler->width = 0;
	handler->prec = -1;
	handler->length = NONE;
	handler->flags.hash = false;
	handler->flags.pad_zero = false;
	handler->flags.force_sign = false;
	handler->flags.pad_right = false;
	handler->flags.space_flag = false;
	return (handler);
}

static int			parse_to_handler(const char **fmt, t_ft_printf *handler,
									va_list va_args)
{
	while ((WIDTH(**fmt) || FLAG(**fmt) || PREC(**fmt) || SIZE(**fmt)) && **fmt)
	{
		while (**fmt && FLAG(**fmt))
			parse_flags(fmt, handler);
		if (**fmt && WIDTH(**fmt))
			parse_width(fmt, handler, va_args);
		if (**fmt && PREC(**fmt))
			parse_precision(fmt, handler, va_args);
		if (**fmt && SIZE(**fmt))
			parse_length(fmt, handler);
	}
	if (**fmt)
		parse_specifier(fmt, handler);
	else
		return (0);
	return (1);
}

int					convert_specifier(int fd, const char **fmt, va_list ap)
{
	t_ft_printf	*handler;
	int			chars_printed;

	handler = init_handler();
	handler->fd = fd;
	if (parse_to_handler(fmt, handler, ap) == 0)
		return (0);
	chars_printed = print_conversion(handler, ap);
	ft_memdel((void **)&handler);
	return (chars_printed);
}
