/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:28:28 by mmalanch          #+#    #+#             */
/*   Updated: 2018/05/24 16:28:30 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 32
# define GNL_ERROR(x) if (x) return (-1);
# define MEM_CHECK(x) if (!(x)) return (-1);
# define READ_SUCCESS 1
# define READ_FINISHED 0

int		get_next_line(const int fd, char **line);
#endif
