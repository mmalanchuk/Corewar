/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:19:06 by adayrabe          #+#    #+#             */
/*   Updated: 2018/08/17 13:19:10 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_SPECIFIER_H
# define FT_HANDLE_SPECIFIER_H

typedef struct		s_specifiers
{
	char *str;
	char *(*func)(va_list ap, t_format_specifier *sp);
}					t_specifiers;

t_specifiers		**make_array_of_specifiers(void);
void				free_specifiers(t_specifiers **sp);
char				*ft_length_none_int(va_list ap, t_format_specifier *sp);
char				*ft_length_none_unsigned_int(va_list ap,
	t_format_specifier *sp);
char				*ft_length_none_floating_point(va_list ap,
	t_format_specifier *sp);
char				*ft_length_none_char(va_list ap, t_format_specifier *sp);
char				*ft_length_none_string(va_list ap, t_format_specifier *sp);
char				*ft_length_none_nothing(va_list ap, t_format_specifier *sp);
char				*ft_length_none_floating_point(va_list ap,
	t_format_specifier *sp);

#endif
