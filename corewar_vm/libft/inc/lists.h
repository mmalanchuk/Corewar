/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:12:58 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:13:15 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include "libft.h"

struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
};

typedef struct s_list	t_list;

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
size_t	ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *list);
void	ft_lst_del_content(void *ptr, size_t size);
t_list	*ft_lst_get_index(t_list *lst, unsigned int index);
void	ft_lst_reverse(t_list **alst);
t_list	*ft_lst_foreach(t_list *head, void *(*f)(void *));
void	ft_lst_foreach_subj(t_list *alst, void (*f)(void *));
t_list	*ft_list_find(t_list *alst, void *data_ref, int (*cmp)());
void	ft_list_remove_if(t_list **alst, void *target, int (*cmp)());
void	ft_list_merge(t_list **alst, t_list *blst);
void	ft_list_sort(t_list **alst, int (*cmp)());
void	ft_sorted_list_insert(t_list **alst, void *data, int (*cmp)());
void	ft_sorted_list_merge(t_list **alst, t_list *blst, int (*cmp)());
void	ft_lst_printout(t_list *list, void (*printer)());
void	ft_lst_printf(t_list *list, const char *format);

#endif
