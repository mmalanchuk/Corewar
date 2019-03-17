/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:32:24 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/22 13:32:27 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

int			ft_atoi_base(const char *str, int base)
{
	int	res;
	int	sign;

	res = 0;
	if (base < 2 || base > 16 || !str)
		return (0);
	while (EXT_SP(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
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
	if (base == 10)
		res *= sign;
	return ((int)res);
}
