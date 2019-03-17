/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:14:34 by mmalanch          #+#    #+#             */
/*   Updated: 2019/03/04 16:14:36 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

int		ft_putchar(char c);
int		ft_putstr(char const *s);
int		ft_putendl(char const *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char const *str, int fd);
int		ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int nb);
void	ft_putnbr_fd(int n, int fd);
int		ft_perror(const char *err_msg);

#endif
