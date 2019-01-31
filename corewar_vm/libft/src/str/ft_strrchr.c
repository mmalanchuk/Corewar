/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:34:42 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 15:34:44 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	PROTECT(s);
	s = ft_strchr(s, '\0');
	if (*s == c)
		return (char *)(s);
	while (*--s)
	{
		if (*s == c)
			return (char *)(s);
	}
	return (NULL);
}
