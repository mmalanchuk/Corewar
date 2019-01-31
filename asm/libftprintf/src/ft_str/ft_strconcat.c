/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:38:04 by adayrabe          #+#    #+#             */
/*   Updated: 2018/09/14 14:38:09 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strconcat(char **s1, char *s2, size_t l1, size_t l2)
{
	char	*temp;
	size_t	i;

	temp = ft_strnew(l1);
	i = 0;
	while (i < l1 && ++i)
		temp[i - 1] = s1[0][i - 1];
	(*s1) ? ft_strdel(s1) : 0;
	*s1 = ft_strnew(l1 + l2);
	i = 0;
	while (i < l1 && ++i)
		s1[0][i - 1] = temp[i - 1];
	i = 0;
	while (i < l2 && ++i)
		s1[0][l1 + i - 1] = s2[i - 1];
	ft_strdel(&temp);
}
