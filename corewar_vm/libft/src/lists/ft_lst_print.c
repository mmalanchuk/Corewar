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

void ft_lst_printf(t_list *list, const char *format)
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
