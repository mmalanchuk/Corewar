/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:53:17 by adayrabe          #+#    #+#             */
/*   Updated: 2017/10/31 18:53:19 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	temp;
	unsigned char	*str;

	i = 0;
	temp = (unsigned char)c;
	str = (unsigned char*)b;
	while (i < len)
	{
		str[i] = temp;
		i++;
	}
	return ((void *)str);
}
