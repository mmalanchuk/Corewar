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

#include <unistd.h>
#include <libft.h>

int	ft_putstr(char const *str)
{
	return ((int)(write(STDOUT_FILENO, str, ft_strlen(str))));
}
