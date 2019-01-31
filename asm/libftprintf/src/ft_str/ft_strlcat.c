/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:25:07 by adayrabe          #+#    #+#             */
/*   Updated: 2017/11/06 17:25:08 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	len = i;
	res = i;
	if (i > size - 1 || size == 0)
		return (size + ft_strlen(src));
	while (src[res - i])
		res++;
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[i - len];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
