/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:46:46 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:46:49 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_printers.h"

static int	print_prefix(t_ft_printf *h, bool neg_sign)
{
	if (h->flags.hash)
	{
		if (h->sp == 'o')
			return (ft_putchar_fd('0', h->fd));
		if (h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
		{
			ft_putchar_fd('0', h->fd);
			ft_putchar_fd((char)(h->sp == 'X' ? 'X' : 'x'), h->fd);
			return (2);
		}
	}
	if (h->flags.force_sign && h->sp == 'd')
		return (ft_putchar_fd((char)(neg_sign ? '-' : '+'), h->fd));
	else if (h->flags.space_flag && h->sp == 'd')
		return (ft_putchar_fd(' ', h->fd));
	return (0);
}

static int	print_precision(t_ft_printf *h, int prec, size_t value_len)
{
	int chars;

	chars = 0;
	while (prec > (int)value_len)
	{
		ft_putchar_fd('0', h->fd);
		chars++;
		prec--;
	}
	return (chars);
}

static int	print_width(t_ft_printf *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len && h->sp != 'c')
		value_len += h->prec - value_len;
	value_len += (h->flags.force_sign || h->flags.space_flag)
				&& h->sp == 'd';
	value_len += h->flags.hash && h->sp == 'o';
	value_len += ((h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
				&& h->flags.hash) * 2;
	h->flags.pad_zero *= !(h->flags.pad_right);
	while (h->width > (int)value_len)
	{
		ft_putchar_fd((char)(h->flags.pad_zero ? '0' : ' '), h->fd);
		chars++;
		h->width--;
	}
	return (chars);
}

int			print_value(t_ft_printf *h, char *result, size_t len, bool neg_sign)
{
	int chars_printed;

	chars_printed = 0;
	chars_printed += (int)len;
	if (ft_strchr("duoxXbp", h->sp))
		h->flags.pad_zero *= h->prec == -1;
	if (h->flags.pad_right)
	{
		chars_printed += print_prefix(h, neg_sign);
		chars_printed += print_precision(h, h->prec, len);
		h->sp == 'c' && h->length != L ? ft_putchar_fd(result[0], h->fd)
										: ft_putstr_fd(result, h->fd);
		chars_printed += print_width(h, len);
	}
	else
	{
		chars_printed += h->flags.pad_zero ? print_prefix(h, neg_sign) : 0;
		chars_printed += print_width(h, len);
		chars_printed += h->flags.pad_zero ? 0 : print_prefix(h, neg_sign);
		chars_printed += print_precision(h, h->prec, len);
		h->sp == 'c' && ft_strequ(result, "\0") ?
		ft_putchar_fd(result[0], h->fd) : ft_putstr_fd(result, h->fd);
	}
	ft_strdel(&result);
	return (chars_printed);
}

int			print_conversion(t_ft_printf *h, va_list args)
{
	int ret;

	ret = 0;
	if (h->sp == 'c' || h->sp == '%' || !ft_strchr("diouxXcsprb%", h->sp))
		ret = print_char(h, args);
	else if (h->sp == 'd')
		ret = print_num_signed(h, args);
	else if (ft_strchr("buoxXp", h->sp))
		ret = print_num_unsigned(h, args);
	else if (h->sp == 's' || h->sp == 'r')
		ret = print_string(h, args);
	return (ret);
}
