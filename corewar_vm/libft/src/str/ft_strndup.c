/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:22:30 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:22:31 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;

	PROTECT(src);
	PROTECT(dest = ft_strnew(n));
	return (ft_strncpy(dest, src, n));
}
