/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 18:44:20 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/08 18:44:24 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_structs.h"
#include <stdarg.h>
#include <unistd.h>

int					add_chars(t_format_specifier *sp, int str_len, char c)
{
	int res;

	res = 0;
	if (c == ' ' && sp->append_string)
		str_len += ft_strlen((sp->append_string));
	if (c == '0' && sp->append_string)
		str_len -= ft_strlen((sp->append_string));
	if (c == ' ' && !sp->pad_with_zeroes)
		while (str_len < sp->width && ++str_len && ++res)
			ft_putchar(' ');
	if (c == '0')
	{
		str_len += sp->null_char;
		while (res != str_len)
		{
			ft_putchar('0');
			res++;
		}
	}
	return (res);
}

int					ft_log2(unsigned int a)
{
	int res;

	if (a == 0)
		return (1);
	res = 0;
	while (a != 0)
	{
		a /= 2;
		res++;
	}
	return (res);
}

void				ft_putwchar(unsigned int a, unsigned char *r)
{
	int	len;
	int i;

	len = 1;
	if (ft_log2(a) <= 7)
		(r[0] = a);
	else
		(r[0] = 128 + (a & 63));
	if (ft_log2(a) > 7 && ++len && ft_log2(a) <= 11)
		(r[1] = (a >> 6) + 192);
	else if (ft_log2(a) > 11)
		(r[1] = ((a >> 6) & 63) + 128);
	if (ft_log2(a) > 11 && ++len && ft_log2(a) <= 16)
		r[2] = (a >> 12) + 224;
	else if (ft_log2(a) > 16)
		(r[2] = ((a >> 12) & 63) + 128);
	if (ft_log2(a) > 16 && ++len)
		r[3] = (a >> 18) + 240;
	i = len;
	while (i--)
		write(1, &r[i], 1);
}

void				ft_putwstr(t_format_specifier *sp)
{
	int				j;
	unsigned char	*r;
	int				i;

	if (!sp->wide_string)
	{
		ft_putstr("(null)");
		return ;
	}
	j = 0;
	while (sp->wide_string[j])
	{
		i = 0;
		r = (unsigned char *)malloc(5);
		while (i <= 4 && ++i)
			r[i - 1] = '\0';
		ft_putwchar(sp->wide_string[j], r);
		free(r);
		j++;
	}
}

int					ft_printf_write_string(char *temp,
	t_format_specifier *sp, int res)
{
	int len;

	(temp) ? (len = (int)ft_strlen(temp)) :
				(len = sp->wide_string_len);
	(!sp->left_justify) ? (res += add_chars(sp, len - sp->null_char, ' ')) : 0;
	(sp->append_string) ? (res += ft_strlen(sp->append_string)) : 0;
	ft_putstr(sp->append_string);
	if (sp->pad_with_zeroes && len < sp->width)
		(res += add_chars(sp, sp->width - len, '0'));
	(sp->wide_string_len) ? ft_putwstr(sp) : ft_putstr(temp);
	(sp->null_char) ? ft_putchar('\0') : 0;
	(sp->left_justify) ? (res += add_chars(sp, len - sp->null_char, ' ')) : 0;
	(temp) ? (res += ft_strlen(temp)) : (res += sp->wide_string_len);
	return (res);
}
