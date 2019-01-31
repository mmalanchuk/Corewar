/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:52:43 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 17:52:44 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if ((sptr) < (dptr))
	{
		dptr += len - 1;
		sptr += len - 1;
		while (len--)
			*dptr-- = *sptr--;
	}
	else
		ft_memcpy(dptr, sptr, len);
	return (dst);
}
