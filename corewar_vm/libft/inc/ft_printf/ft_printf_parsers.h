/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:13:20 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:13:21 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSERS_H
# define FT_PRINTF_PARSERS_H

# include "ft_printf.h"
# include "ft_printf_utils.h"

# define FLAG(x) ft_strchr("-+ 0#", (x))
# define WIDTH(x) (ft_isdigit(x) || (x) == '*')
# define PREC(x) ((x) == '.')
# define SIZE(x) (ft_strchr("hljz", (x)))

void parse_width(const char **fmt, t_ft_printf *handler, va_list args);

void parse_precision(const char **fmt, t_ft_printf *handler, va_list args);

void parse_flags(const char **fmt, t_ft_printf *handler);

void parse_length(const char **fmt, t_ft_printf *handler);

void parse_specifier(const char **fmt, t_ft_printf *handler);

#endif
