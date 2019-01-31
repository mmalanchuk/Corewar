/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:14:41 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 17:14:43 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	if (!dst && !src)
		return (NULL);
	dptr = (unsigned char *)dst;
	sptr = (const unsigned char *)src;
	while (n--)
		*dptr++ = *sptr++;
	return (dst);
}
