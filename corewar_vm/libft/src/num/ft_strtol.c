/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:00:33 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:01:40 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

long	ft_strtol(const char *str, char **endptr, int base)
{
	long	res;
	bool	sign;

	res = 0;
	if (str == NULL || base > 16 || base < 2)
		return (0);
	while (EXT_SP(*str))
		str++;
	sign = *str == '-';
	if (*str == '-' || *str == '+')
		str++;
	while (ft_in_base(*str, base))
	{
		if (*str - 48 < 10)
			res = res * base + *str - 48;
		else
			res = res * base + *str + 10 - (FT_LCASE(*str) ? 97 : 65);
		str++;
	}
	if (sign && base == 10)
		res *= -sign;
	if (endptr)
		*endptr = (char *)str;
	return (res);
}
