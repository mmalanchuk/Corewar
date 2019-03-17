/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:32:52 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 18:32:53 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_array(char **tab)
{
	unsigned int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	PROTECT(s);
	PROTECT(tab = (char **)malloc(sizeof(*tab) * (ft_count_words(s, c) + 1)));
	i = 0;
	j = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else if (s += i)
		{
			i = 0;
			while (s[i] != c && s[i])
				i++;
			if (!(tab[j] = ft_strnew(i)))
			{
				free_array(tab);
				return (NULL);
			}
			ft_strncpy(tab[j++], s, i);
		}
	tab[j] = NULL;
	return (tab);
}
