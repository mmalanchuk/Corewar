/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:08:46 by adayrabe          #+#    #+#             */
/*   Updated: 2017/11/06 17:08:47 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
	size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)src;
	str = (unsigned char*)dst;
	while (i < n)
	{
		*str = *temp;
		i++;
		str++;
		if (*temp == (unsigned char)c)
			return (str);
		temp++;
	}
	return (0);
}
