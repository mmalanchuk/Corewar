/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:05:51 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:05:59 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stddef.h>

# define FT_ABS(x)		(((x) < 0) ? -(x) : (x))
# define FT_MAX(a, b) ((a) > (b) ? (a) : (b))
# define FT_MIN(a, b) ((a) < (b) ? (a) : (b))

size_t	ft_factorial(size_t num);
size_t	ft_pow(int num, int power);

#endif
