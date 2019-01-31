/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_unsigned_concat.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:07:30 by adayrabe          #+#    #+#             */
/*   Updated: 2018/10/17 19:07:31 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_unsigned_concat(unsigned char **s1, unsigned char *s2,
	size_t l1, size_t l2)
{
	unsigned char	*temp;
	size_t			i;

	temp = ft_str_unsigned_new(l1);
	i = 0;
	while (i < l1 && ++i)
		temp[i - 1] = s1[0][i - 1];
	(*s1) ? ft_str_unsigned_del(s1) : 0;
	*s1 = ft_str_unsigned_new(l1 + l2);
	i = 0;
	while (i < l1 && ++i)
		s1[0][i - 1] = temp[i - 1];
	i = 0;
	while (i < l2 && ++i)
		s1[0][l1 + i - 1] = s2[i - 1];
	ft_str_unsigned_del(&temp);
}
