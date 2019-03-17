/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorial.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:28:00 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:28:05 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_math.h"

size_t	ft_factorial(size_t num)
{
	if (num > 20)
	{
		ft_perror("The output is larger than 'size_t' limit!");
		exit(EXIT_FAILURE);
	}
	if (num == 0 || num == 1)
		return (1);
	num *= ft_factorial(num - 1);
	return (num);
}
