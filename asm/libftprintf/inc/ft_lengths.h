/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:29:17 by adayrabe          #+#    #+#             */
/*   Updated: 2018/08/17 13:29:19 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LENGTHS_H
# define FT_LENGTHS_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include "printf_structs.h"

void ft_printf_add_length(const char **s, t_format_specifier *sp);
char *ft_length_ll(va_list ap, const char **s,
	int res, t_format_specifier *specifier);
char *ft_length_l(va_list ap, const char **s, int res,
	t_format_specifier *specifier);
char *ft_length_none(va_list ap, const char **s, int res,
	t_format_specifier *specifier);
char *ft_length_h(va_list ap, const char **s, int res,
	t_format_specifier *specifier);
char *ft_length_hh(va_list ap, const char **s, int res,
	t_format_specifier *specifier);
char *ft_length_j(va_list ap, const char **s, int res,
	t_format_specifier *specifier);
char *ft_length_z(va_list ap, const char **s, int res,
	t_format_specifier *specifier);
char *ft_length_l_unsigned_int(va_list ap, t_format_specifier *sp);
char *ft_length_l_signed_int(va_list ap, t_format_specifier *sp);
char *ft_length_l_char(va_list ap, t_format_specifier *sp);
char *ft_length_l_string(va_list ap, t_format_specifier *sp);
#endif
