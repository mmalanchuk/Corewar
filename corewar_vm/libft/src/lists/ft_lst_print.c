/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:05:28 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/06 15:05:29 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_printout(t_list *list, void (*printer)())
{
	while (list)
	{
		ft_putstr("[");
		printer(list->content);
		ft_putstr("]->");
		list = list->next;
	}
	ft_putendl(RED"X\n"RESET);
}

void	ft_lst_printf(t_list *list, const char *format)
{
	while (list)
	{
		ft_putstr("[");
		ft_printf(format, list->content);
		ft_putstr("]->");
		list = list->next;
	}
	ft_putendl(RED"X\n"RESET);
}
