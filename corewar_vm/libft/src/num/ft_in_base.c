/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:00:19 by mmalanch          #+#    #+#             */
/*   Updated: 2018/12/21 19:00:20 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

bool	ft_in_base(char c, int base)
{
	if (base < 2 || base > 16 || !c)
		return (false);
	if (ft_isalpha(c))
		return ((c > 64 && c < 55 + base) || (c > 96 && c < 87 + base));
	if (ft_isdigit(c))
		return (c < 48 + base);
	return (false);
}
