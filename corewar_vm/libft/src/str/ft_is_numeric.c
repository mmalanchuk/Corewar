/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:18:43 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:18:47 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

bool	ft_is_numeric(const char *str)
{
	int	i;

	PROTECT(str);
	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (i != 0);
}
