/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:33:01 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 18:33:03 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	neg;
	size_t	len;
	int		i;

	neg = (n < 0) ? 1 : 0;
	len = ft_numlen(n) + neg;
	if (!(ret = ft_strnew(len)))
		return (NULL);
	i = 0;
	if (n == 0)
		ret[i] = '0';
	while (n)
	{
		ret[i++] = FT_ABS(n % 10) + 48;
		n /= 10;
	}
	if (neg)
		ret[i] = '-';
	ret[++i] = '\0';
	ret = ft_strrev(ret);
	return (ret);
}
