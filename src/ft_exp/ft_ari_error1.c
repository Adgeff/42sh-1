/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_error1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 07:52:17 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:47:09 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_ari_already_incrdecr(char *input, char *varname, char *token)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(varname, STDERR_FILENO);
	ft_putstr_fd(": variable already incremented/decremented (error token is `",
		STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
	return (-1);
}

int		ft_ari_missing_parenthesis(char *input)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": missing `)'\n", STDERR_FILENO);
	return (-1);
}

int		ft_ari_negative_exponent(char *input)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": exponent less than 0\n", STDERR_FILENO);
	return (-1);
}

int		ft_ari_non_variable(char *input, char *token)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": attempted assignment to non-variable (error token is `",
		STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
	return (-1);
}

int		ft_ari_operand_expected(char *input, char *token)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": operand expected (error token is `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
	return (-1);
}
