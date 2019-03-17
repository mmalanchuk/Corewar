/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:44:09 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:26:21 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned num;

	if (nb < 0)
		ft_putchar('-');
	num = (unsigned)FT_ABS(nb);
	if (num / 10)
		ft_putnbr(num / 10);
	ft_putchar((char)(num % 10 + '0'));
}
