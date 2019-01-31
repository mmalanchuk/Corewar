/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:33:17 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 17:33:18 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;
	unsigned char		ch;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n--)
	{
		*dptr++ = *sptr;
		if (*sptr == ch)
			return (dptr);
		sptr++;
	}
	return (NULL);
}
