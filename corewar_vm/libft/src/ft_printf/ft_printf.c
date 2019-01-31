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

int			ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int chars_printed;

	if (fmt == NULL)
		return (-1);
	chars_printed = 0;
	while (*fmt)
		if (*fmt == START_SPEC)
		{
			++fmt;
			chars_printed += convert_specifier(fd, &fmt, ap);
		}
		else
		{
			chars_printed += ft_putchar_fd(*fmt, fd);
			fmt++;
		}
	return (chars_printed);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		done;

	va_start(ap, format);
	done = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (done);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		done;

	va_start(ap, format);
	done = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (done);
}
