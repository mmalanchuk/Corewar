/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:21:56 by adayrabe          #+#    #+#             */
/*   Updated: 2017/11/07 20:21:56 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	i = 0;
	while (*s1 && i < n - 1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
