/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:19:03 by adayrabe          #+#    #+#             */
/*   Updated: 2017/11/06 17:19:05 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*res;
	size_t	i;

	length = 0;
	if (!s1)
		return (NULL);
	while (s1[length])
		length++;
	res = (char *)malloc(length + 1);
	if (res)
	{
		i = 0;
		while (i < length)
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
