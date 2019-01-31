/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:34:11 by adayrabe          #+#    #+#             */
/*   Updated: 2018/01/23 16:34:18 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char	*make_zero(void)
{
	char *res;

	res = malloc(1);
	res[0] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		sp;
	int		end;
	int		i;

	sp = 0;
	while (s && (s[sp] == ' ' || s[sp] == '\t' || s[sp] == '\n'))
		sp++;
	end = 0;
	s ? (end = (int)ft_strlen(s) - 1) : 0;
	while (s && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (s && ft_strlen(s) <= (sp + (ft_strlen(s) - end)))
		return (make_zero());
	res = NULL;
	s ? (res = (char *)malloc(end - sp + 2)) : 0;
	if (!(res && s))
		return (NULL);
	i = 0;
	while (sp <= end && ++sp && ++i)
		res[i - 1] = s[sp - 1];
	res[i] = '\0';
	return (res);
}
