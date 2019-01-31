/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:31:21 by adayrabe          #+#    #+#             */
/*   Updated: 2018/08/17 13:31:23 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_STRUCTS_H
# define PRINTF_STRUCTS_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct	s_format_specifier
{
	char	left_justify : 1;
	char	preceed_sign : 1;
	char	insert_blanck_space : 1;
	char	has_hashtag : 1;
	char	pad_with_zeroes : 1;
	int		width;
	int		precision;
	char	*(*func)(va_list ap, const char **s,
		int res, struct s_format_specifier *sp);
	char	null_char : 1;
	char	*append_string;
	char	specifier;
	wchar_t	*wide_string;
	int		wide_string_len;
}				t_format_specifier;

typedef struct	s_length
{
	char c;
	char *(*func)(va_list ap, const char **s, int res, t_format_specifier *sp);
}				t_length;

#endif
