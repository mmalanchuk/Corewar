/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:21:14 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/22 13:21:15 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	char	*ret;
	size_t	neg;
	size_t	len;
	int		i;

	neg = (n < 0) ? 1 : 0;
	len = ft_numlen(n) + neg;
	if (!(ret = ft_strnew(len)) || base < 2 || base > 16)
		return (NULL);
	i = 0;
	if (n == 0)
		ret[i] = '0';
	while (n)
	{
		if (n % base < 10)
			ret[i] = FT_ABS(n % base) + 48;
		else
			ret[i] = FT_ABS(n % base) - 10 + 65;
		n /= base;
		i++;
	}
	if (neg && base == 10)
		ret[i] = '-';
	ret[++i] = '\0';
	return (ft_strrev(ret));
}
