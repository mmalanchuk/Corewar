/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:34:17 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 15:34:18 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	PROTECT(s);
	while (*s)
	{
		if (*s == c)
			return (char *)(s);
		s++;
	}
	if (*s == c)
		return (char *)(s);
	return (NULL);
}
