/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:25:39 by mmalanch          #+#    #+#             */
/*   Updated: 2017/09/26 18:25:42 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	int					i;

	res = 0;
	i = 0;
	while (FT_EXSPACE(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - 48;
	if (res > LONG_MAX)
		return ((sign == 1) ? -1 : 0);
	return ((int)res * sign);
}
