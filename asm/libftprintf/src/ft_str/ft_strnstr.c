/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:55:13 by adayrabe          #+#    #+#             */
/*   Updated: 2017/11/06 17:55:14 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (*big && i < len)
	{
		if (*big == little[0])
		{
			j = -1;
			flag = 0;
			while (little[++j] && i + j < len)
				if (little[j] != big[j])
					flag = 1;
			if (flag == 0 && little[j] == '\0')
				return ((char *)big);
		}
		i++;
		big++;
	}
	return (0);
}
