/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:14:35 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/06 16:14:36 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_printers.h"

static char	*get_char(const int code)
{
	char *buffer;

	buffer = ft_strnew(3);
	if (code == 8)
		ft_strcpy(buffer, "\\b");
	else if (code == 9)
		ft_strcpy(buffer, "\\t");
	else if (code == 10)
		ft_strcpy(buffer, "\\n");
	else if (code == 11)
		ft_strcpy(buffer, "\\v");
	else if (code == 12)
		ft_strcpy(buffer, "\\f");
	else if (code == 13)
		ft_strcpy(buffer, "\\r");
	else if (code == 27)
		ft_strcpy(buffer, "\\e");
	else if (code >= 0 && code < 32)
	{
		buffer[0] = '^';
		buffer[1] = (char)('@' + code);
	}
	else
		buffer[0] = (char)code;
	return (buffer);
}

static char	*show_non_printable(char *str, int prec)
{
	char	*buf;
	char	*ret;
	int		i;

	if (str == NULL)
		return (ft_strdup("(null)"));
	ret = ft_strnew(0);
	i = -1;
	while (str[++i])
	{
		buf = get_char(str[i]);
		if (prec != -1 && prec < (int)(ft_strlen(buf) + ft_strlen(ret)))
		{
			ft_strdel(&buf);
			break ;
		}
		ret = printf_strjoin(ret, buf);
	}
	ft_strdel(&str);
	return (ret);
}

static char	*get_wstr(wchar_t *value, int prec)
{
	char *res;
	char *wchar;

	if (value == NULL)
		return (ft_strdup("(null)"));
	res = ft_strnew(0);
	while (*value)
	{
		wchar = get_wchar(*value);
		if (prec != -1 && prec < (int)(ft_strlen(wchar) + ft_strlen(res)))
		{
			ft_strdel(&wchar);
			break ;
		}
		res = printf_strjoin(res, wchar);
		value++;
	}
	return (res);
}

char		*precision_cut(char *src, int prec)
{
	char *dest;

	if (prec >= 0 && prec < (int)ft_strlen(src))
	{
		dest = ft_strnew((size_t)prec);
		if (dest)
			ft_strncpy(dest, src, (size_t)prec);
		ft_strdel(&src);
		return (dest);
	}
	else
		return (src);
}

int			print_string(t_ft_printf *h, va_list args)
{
	char	*value;
	char	*result;

	if (h->length == L && h->sp == 's')
		result = get_wstr(va_arg(args, wchar_t *), h->prec);
	else
	{
		value = va_arg(args, char *);
		result = ft_strdup(value == NULL ? "(null)" : value);
	}
	if (h->sp == 'r')
		result = show_non_printable(result, h->prec);
	if (h->sp == 's' && h->length != L)
		result = precision_cut(result, h->prec);
	h->prec = -1;
	return (print_value(h, result, ft_strlen(result), false));
}
