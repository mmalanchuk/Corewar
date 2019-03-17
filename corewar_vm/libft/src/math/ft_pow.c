/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:28:16 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:28:17 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

size_t	ft_pow(int num, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num *= ft_pow(num, power - 1);
	return (size_t)(num);
}
