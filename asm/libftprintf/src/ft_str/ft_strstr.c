/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:56:31 by adayrabe          #+#    #+#             */
/*   Updated: 2017/09/26 12:56:57 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int temp;

	i = 0;
	if (str[i] == '\0' && to_find[i] == '\0')
		return (&str[i]);
	while (str[i] != '\0')
	{
		j = 0;
		temp = i;
		while (str[temp] == to_find[j] && to_find[j] != '\0')
		{
			j++;
			temp++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
