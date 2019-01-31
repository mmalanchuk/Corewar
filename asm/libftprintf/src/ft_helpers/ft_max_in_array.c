/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_in_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:31:13 by adayrabe          #+#    #+#             */
/*   Updated: 2018/01/30 15:31:13 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_in_array(int *arr, size_t size)
{
	size_t	i;
	int		max;

	if (!arr)
		return (0);
	max = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}
