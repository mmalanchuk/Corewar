/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:25:13 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:25:16 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "ft_printf.h"

char			*convert_base(size_t unsgnd,
							int base, bool upper_case, bool is_unsigned);
bool			check_val_prec(int prec, char **result);
size_t			get_numlen(size_t usigned_num, int base, bool is_unsigned);
unsigned int	count_bits(unsigned int value);
char			*printf_strjoin(char *s1, char *s2);
int				convert_specifier(int fd, const char **fmt, va_list ap);

#endif
