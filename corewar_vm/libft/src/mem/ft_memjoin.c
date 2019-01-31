/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:01:36 by mmalanch          #+#    #+#             */
/*   Updated: 2018/10/24 21:01:37 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *dest, void *src, size_t d_len, size_t s_len)
{
	void *ret;

	if (!dest && !src)
		return (NULL);
	ret = ft_memalloc(d_len + s_len + 1);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, dest, d_len);
	ft_memcpy(ret + d_len, src, s_len);
	ft_memdel(&dest);
	return (ret);
}
