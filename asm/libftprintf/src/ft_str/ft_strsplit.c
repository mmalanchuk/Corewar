/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:54:08 by adayrabe          #+#    #+#             */
/*   Updated: 2017/11/27 19:54:09 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *str, char c)
{
	int len;

	len = 0;
	while (*str && *str != c)
	{
		str++;
		len++;
	}
	return (len);
}

static int	words(const char *s, char c)
{
	int i;
	int words;
	int flag;

	if (!s)
		return (-1);
	if (!(*s))
		return (0);
	flag = 0;
	i = -1;
	words = 0;
	while (s[++i])
		if (s[i] == c && flag == 1 && ++words)
			flag = 0;
		else if (s[i] != c)
			flag = 1;
	if (s[i - 1] != c)
		words++;
	return (words);
}

static void	free_arr(char ***arr, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		ft_strdel(&arr[0][i]);
		i++;
	}
	free(*arr);
}

static int	do_a(char **res, int word, int *i, int len)
{
	res[word] = ft_strnew(len);
	if (!res[word])
	{
		free_arr(&res, word);
		return (1);
	}
	res[word - 1][*i] = '\0';
	*i = 0;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		flag;
	int		i;
	int		word;
	int		j;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (words(s, c) + 1))))
		return (NULL);
	i = 0;
	flag = 0;
	word = 0;
	res[word] = ft_strnew(ft_len(s, c) + 1);
	j = -1;
	while (s[++j])
	{
		if (s[j] == c && flag != 0 && ++word)
			if ((flag = do_a(res, word, &i, ft_len(&s[j + 1], c) + 1)) == 1)
				return (NULL);
		(s[j] != c && ++i && ++flag) ? (res[word][i - 1] = s[j]) : 0;
	}
	res[word + (words(s, c) == 0 || (s[j - 1]) == c) * -1 + 1] = 0;
	return (res);
}
