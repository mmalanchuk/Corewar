/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_unsigned_new.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:07:49 by adayrabe          #+#    #+#             */
/*   Updated: 2018/10/17 19:07:51 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_str_unsigned_new(size_t len)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)malloc(len + 1);
	i = 0;
	while (i <= len)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
