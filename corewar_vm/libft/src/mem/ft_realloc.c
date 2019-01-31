/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:02:14 by mmalanch          #+#    #+#             */
/*   Updated: 2018/10/24 21:02:15 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_len, size_t new_len)
{
	void *ptr_new;

	if (new_len == 0)
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	else if (!ptr)
		return (ft_memalloc(new_len));
	else if (new_len <= old_len)
		return (ptr);
	else
	{
		ptr_new = ft_memalloc(new_len);
		if (ptr_new)
		{
			ft_memcpy(ptr_new, ptr, old_len);
			ft_memdel(&ptr);
		}
		return (ptr_new);
	}
}
