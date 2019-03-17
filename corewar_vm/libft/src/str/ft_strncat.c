/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 19:59:43 by mmalanch          #+#    #+#             */
/*   Updated: 2017/09/26 19:59:44 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	dlen;

	PROTECT(dest && src);
	dlen = ft_strlen(dest);
	while (*src && nb--)
	{
		dest[dlen] = *src++;
		dlen++;
	}
	dest[dlen] = '\0';
	return (dest);
}
