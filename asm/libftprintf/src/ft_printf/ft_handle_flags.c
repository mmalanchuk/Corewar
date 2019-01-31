/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:40:36 by adayrabe          #+#    #+#             */
/*   Updated: 2018/07/04 17:40:38 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lengths.h"

void		ft_printf_add_flags(const char **s, t_format_specifier *sp)
{
	while (**s == '+' || **s == '-' || **s == ' ' || **s == '#' || **s == '0')
	{
		if (s[0][0] == '+')
			sp->preceed_sign = 1;
		if (s[0][0] == ' ')
			sp->insert_blanck_space = 1;
		if (s[0][0] == '#')
			sp->has_hashtag = 1;
		if (s[0][0] == '0' && !sp->left_justify)
			sp->pad_with_zeroes = 1;
		if (s[0][0] == '-')
		{
			sp->left_justify = 1;
			sp->pad_with_zeroes = 0;
		}
		(*s)++;
	}
}

void		ft_printf_add_width(va_list ap, const char **s,
							t_format_specifier *sp)
{
	if (**s == '*')
	{
		(*s)++;
		sp->width = va_arg(ap, int);
		if (sp->width < 0)
		{
			sp->width *= -1;
			sp->left_justify = 1;
		}
	}
	else
	{
		sp->width = ft_atoi(s[0]);
		while (ft_isdigit(s[0][0]))
			(*s)++;
	}
}

void		ft_printf_add_precision(va_list ap, const char **s,
									t_format_specifier *sp)
{
	(*s)++;
	if (**s == '*')
	{
		sp->precision = va_arg(ap, int);
		if (sp->precision < 0)
			sp->precision = -1;
		(*s)++;
	}
	else
	{
		sp->precision = ft_atoi(s[0]);
		while (ft_isdigit(s[0][0]))
			(*s)++;
	}
}

int			is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	if (ft_isdigit(c) || c == '*')
		return (2);
	if (c == '.')
		return (3);
	if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (4);
	return (0);
}

void		ft_handle_flags(va_list ap, const char **s, t_format_specifier *sp)
{
	while (is_flag(**s))
	{
		if (is_flag(**s) == 1)
			ft_printf_add_flags(s, sp);
		if (is_flag(**s) == 2)
			ft_printf_add_width(ap, s, sp);
		if (is_flag(**s) == 3)
			ft_printf_add_precision(ap, s, sp);
		if (is_flag(**s) == 4)
			ft_printf_add_length(s, sp);
	}
	if (sp->func == NULL)
		ft_printf_add_length(s, sp);
}
