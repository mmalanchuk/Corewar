/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:56:27 by mmalanch          #+#    #+#             */
/*   Updated: 2018/10/07 15:56:29 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H
# include <stdbool.h>

typedef enum	e_fpf_length
{
	NONE, HH, H, L, LL, J, Z
}				t_fpf_length;

typedef struct	s_fpf_flags
{
	bool pad_right;
	bool pad_zero;
	bool force_sign;
	bool space_flag;
	bool hash;
}				t_fpf_flags;

typedef struct	s_ft_printf
{
	int				fd;
	t_fpf_flags		flags;
	int				width;
	int				prec;
	t_fpf_length	length;
	char			sp;
}				t_ft_printf;

#endif
