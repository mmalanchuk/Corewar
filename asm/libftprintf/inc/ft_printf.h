/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:30:17 by adayrabe          #+#    #+#             */
/*   Updated: 2018/08/17 13:30:19 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_helpers.h"

int	ft_printf_write_string(char *temp,
	t_format_specifier *sp, int res);

#endif
