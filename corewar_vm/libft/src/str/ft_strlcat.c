/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:04:38 by mmalanch          #+#    #+#             */
/*   Updated: 2017/09/26 20:04:40 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dptr;
	const char	*sptr;
	size_t		n;
	size_t		dlen;

	dptr = dst;
	sptr = src;
	n = size;
	while (n-- && *dptr)
		dptr++;
	dlen = dptr - dst;
	n = size - dlen;
	if (!n)
		return (dlen + ft_strlen(sptr));
	while (*sptr)
	{
		if (n != 1)
		{
			*dptr++ = *sptr;
			n--;
		}
		sptr++;
	}
	*dptr = '\0';
	return (dlen + (sptr - src));
}
