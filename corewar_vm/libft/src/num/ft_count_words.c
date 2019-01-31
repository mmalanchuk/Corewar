/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:34:09 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/20 15:34:12 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(char const *s, char c)
{
	int	words_num;

	words_num = 0;
	while (*s)
		if (*s == c)
			s++;
		else
		{
			words_num++;
			while (*s != c && *s)
				s++;
		}
	return (words_num);
}
