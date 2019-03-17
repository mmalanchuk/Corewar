/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:32:26 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 18:32:28 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	PROTECT(s1 && s2);
	PROTECT(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2)));
	ret = ft_strcat(ft_strcat(ret, s1), s2);
	return (ret);
}
