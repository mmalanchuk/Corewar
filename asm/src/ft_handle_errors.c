/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adayrabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:14:01 by adayrabe          #+#    #+#             */
/*   Updated: 2019/01/30 20:14:02 by adayrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_operations(t_operation **head)
{
	t_operation *temp;

	while (*head)
	{
		temp = (*head)->next;
		ft_str_unsigned_del(&((*head)->code));
		ft_strdel(&((*head)->label1->arg));
		ft_strdel(&((*head)->label2->arg));
		free((*head)->label1);
		(*head)->label1 = NULL;
		free((*head)->label2);
		(*head)->label2 = NULL;
		free(*head);
		*head = NULL;
		*head = temp;
	}
}

void	free_addresses(t_address **head)
{
	t_address *temp;

	while (head && *head)
	{
		temp = (*head)->next;
		free_operations(&(*head)->operations);
		free(*head);
		*head = temp;
	}
}

char	**make_errors(char **errors)
{
	errors[0] = "WRONG OPERATOR";
	errors[1] = "SEPARATOR CHAR BETWEEN NAME AND ARGS";
	errors[2] = "NO ARGUMENTS";
	errors[3] = "WRONG SYMBOL IN LABEL NAME";
	errors[4] = "NOT ENOUGH ARGUMENTS";
	errors[5] = "WRONG SYMBOL FOR ARGUMENT";
	errors[6] = "SYMBOL AFTER LAST ARGUMENT";
	errors[7] = "NOT ENOUGH ARGUMENTS OR NO SEPARATOR";
	errors[8] = "WRONG REG NUMBER";
	errors[9] = "WRONG SYMBOL, HAS TO BE DIGIT";
	errors[10] = "ILLEGAL CHARACTER IN LABEL";
	errors[11] = "T_REG CAN NOT BE ARGUMENT FOR THIS OPERATION";
	errors[12] = "T_DIR CAN NOT BE ARGUMENT FOR THIS OPERATION";
	errors[13] = "T_IND CAN NOT BE ARGUMENT FOR THIS OPERATION";
	errors[15] = "WRONG END OF FILE (NO EMPTY LINE)";
	errors[16] = "SEPARATOR CHAR BEFORE OPERATOR";
	errors[17] = "WRONG SYMBOLS BEFORE .NAME OR .COMMENT";
	errors[18] = "WRONG SYMBOLS AFTER .NAME OR .COMMENT";
	errors[19] = "END OF FILE AND NO OPERATORS OR LABEL";
	errors[20] = "NAME COMMAND SECOND TIME";
	errors[21] = "COMMENT COMMAND SECOND TIME";
	errors[22] = "THIS LABEL DOES NOT EXIST";
	errors[23] = "WRONG SYMBOL BETWEEN ARG AND SEPARATOR";
	return (errors);
}

void	ft_handle_errors(t_error *error, t_argument ***arguments)
{
	char	**errors;
	int		i;

	errors = (char **)malloc(sizeof(char *) * 24);
	errors = make_errors(errors);
	ft_printf("ERROR AT [%d, %d] %s\n", error->line, error->column,
		errors[error->num]);
	i = -1;
	while (arguments && arguments[0] && arguments[0][++i])
	{
		ft_strdel(&(arguments[0][i]->arg));
		free(arguments[0][i]);
		arguments[0][i] = NULL;
	}
	if (arguments && *arguments)
		free(*arguments);
	free(errors);
	free_addresses(error->head);
	free(error);
	exit(0);
}
