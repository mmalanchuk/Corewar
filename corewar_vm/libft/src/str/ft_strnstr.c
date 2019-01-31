/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:24:57 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 15:24:58 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		little_len;
	size_t		temp;

	PROTECT(big)
	little_len = ft_strlen(little);
	if (!little_len || big == little)
		return ((char*)big);
	i = 0;
	while (big[i] && len)
	{
		j = 0;
		temp = len;
		while (big[i + j] == little[j] && temp)
		{
			if (j == little_len - 1)
				return ((char*)(big + i));
			j++;
			temp--;
		}
		len--;
		i++;
	}
	return (NULL);
}
