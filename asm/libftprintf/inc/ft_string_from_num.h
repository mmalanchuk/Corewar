/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_from_num.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:31:01 by adayrabe          #+#    #+#             */
/*   Updated: 2018/08/17 13:31:03 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_FROM_NUM_H
# define FT_STRING_FROM_NUM_H

char *ft_string_from_num_signed(intmax_t a, t_format_specifier *sp);
char *ft_string_from_num_unsigned(uintmax_t a, char c, t_format_specifier *sp);
char *ft_string_from_num_double(long double a, char c, t_format_specifier *sp);

#endif
