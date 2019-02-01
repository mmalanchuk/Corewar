/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:23:59 by adayrabe          #+#    #+#             */
/*   Updated: 2017/09/25 18:23:59 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\r')
		return (1);
	if (str == '\n' || str == '\f' || str == '\v')
		return (1);
	return (0);
}

int				ft_atoi(char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while (is_space(str[i]) == 1)
		i++;
	if ((str[i] == '-' || str[i] == '+') && ++i)
		(str[i - 1] == '-') ? (sign = -1) : 0;
	while (str[i] >= '0' && str[i] <= '9' && ++i)
	{
		if (res > 9223372036854775807)
			return ((sign == -1) - 1);
		res = res * 10 + str[i - 1] - 48;
	}
	return ((int)(sign * res));
}
