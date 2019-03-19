/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 14:43:14 by mmalanch          #+#    #+#             */
/*   Updated: 2017/09/26 14:43:18 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	int ret;

	ret = ft_putstr_fd(s, fd);
	ret += ft_putchar_fd('\n', fd);
	return (ret);
}
