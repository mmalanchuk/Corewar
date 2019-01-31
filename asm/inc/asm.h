/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:10:32 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/31 15:10:34 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"
# include "libft.h"

typedef struct	s_argument
{
	char	*arg;
	int		row;
	int		col;
	int		position;
	int		length;
}				t_argument;

typedef struct	s_operation
{
	unsigned char		*code;
	unsigned int		length;
	int					line;
	t_argument			*label1;
	t_argument			*label2;
	int					position1;
	int					position2;
	struct s_operation	*next;
}				t_operation;

typedef struct	s_address
{
	char				*name;
	t_operation			*operations;
	unsigned int		length;
	struct s_address	*next;
}				t_address;

typedef struct	s_error
{
	int			line;
	int			column;
	int			num;
	t_address	**head;
}				t_error;

t_argument		**ft_split_line(char *line, int row, int col);
int				ft_parse_operations(t_argument **arguments, t_address **head,
	int row, char **line);
void			ft_handle_errors(t_error *error, t_argument ***arguments);
int				find_index(char *op_name);
t_error			*make_error(int line, int col, int num, t_address **head);
unsigned int	count_operation_size(t_argument **arguments, char *line,
	int row, t_address **head);
int				turn_to_code(t_operation *op, t_argument **arguments,
	t_address *head, int *arg_position);
int				parse_line(char *line, t_address **head, int row);
t_header		*make_header(int *l, int fd);
void			add_number(unsigned int nbr, t_operation *op, int position,
	int length);
t_argument		*make_arg(char *name, int row, int col, int position);
void			free_operations(t_operation **head);
void			add_label(t_operation *op, t_arg_type arg);
void			add_dir_on_indir(t_argument *arg, int *position,
	t_address *head, t_operation *op);
void        make_code(t_address **head, t_header *header, unsigned char **word);
#endif
