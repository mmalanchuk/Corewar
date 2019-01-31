/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:14:57 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/14 15:14:58 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/**
 *  system headers
 */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

/**
 * my own headers
 */

# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "ctype.h"
# include "btree.h"
# include "lists.h"
# include "str.h"
# include "num.h"
# include "mem.h"
# include "printers.h"
# include "stack.h"
# include "ft_math.h"
# include "queue.h"
/**
 * useful macros
 */
# define FT_SPACE(x)	((x) == ' ' || (x) == '\n' || (x) == '\t' )
# define PROTECT(x) if (!(x)) return (NULL);

#endif
