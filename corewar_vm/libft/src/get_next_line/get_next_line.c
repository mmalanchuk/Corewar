/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:31:32 by mmalanch          #+#    #+#             */
/*   Updated: 2018/05/24 16:31:36 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*match_fd(size_t fd, t_list **file)
{
	t_list *temp;

	temp = *file;
	while (temp)
	{
		if (temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	temp = *file;
	return (temp);
}

static int		read_line(void **buf, char **line)
{
	char *nl;
	void *to_free;

	if (*buf && *(char *)*buf)
	{
		if ((nl = ft_strchr(*buf, 10)))
		{
			to_free = *buf;
			*nl = '\0';
			*line = ft_strdup(*buf);
			*buf = ft_strdup(nl + 1);
			ft_memdel(&to_free);
			return (READ_SUCCESS);
		}
		else
		{
			*line = ft_strdup(*buf);
			ft_memdel(buf);
			return (READ_SUCCESS);
		}
	}
	return (READ_FINISHED);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*curr;
	char			*temp;
	void			*to_free;

	GNL_ERROR(fd < 0 || read(fd, 0, 0) < 0 || line == NULL || BUFF_SIZE <= 0);
	MEM_CHECK(curr = match_fd((size_t)fd, &files));
	MEM_CHECK(temp = ft_strnew(BUFF_SIZE));
	while (read(curr->content_size, temp, BUFF_SIZE) > 0)
	{
		to_free = curr->content;
		MEM_CHECK(curr->content = ft_strjoin(curr->content, temp));
		ft_memdel(&to_free);
		ft_strclr(temp);
		if (ft_strchr(curr->content, '\n'))
			break ;
	}
	ft_strdel(&temp);
	return (read_line(&curr->content, line));
}
