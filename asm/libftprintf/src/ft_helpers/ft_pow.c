/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:41:42 by adayrabe          #+#    #+#             */
/*   Updated: 2018/09/06 11:41:43 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_pow(size_t x, int pow)
{
	unsigned long res;

	res = 1;
	while (pow > 0)
	{
		res = res * x;
		pow--;
	}
	return (res);
}
