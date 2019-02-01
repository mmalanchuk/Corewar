/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:28:23 by adayrabe          #+#    #+#             */
/*   Updated: 2018/01/23 16:28:36 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		num;

	len = 0;
	num = n;
	while (num != 0 && ++len)
		num /= 10;
	if (n <= 0)
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	(n < 0) ? (res[0] = '-') :
	(res[0] = '0');
	res[len--] = '\0';
	while (n != 0 && --len > -5)
	{
		res[len + 1] = '0' + (((n > 0) - 1) * 2 + 1) * (n % 10);
		n /= 10;
	}
	return (res);
}
