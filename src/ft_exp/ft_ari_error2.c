/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 10:03:06 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:47:14 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_ari_recursion_exceeded(char *input, char *token)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": expression recursion level exceeded (error token is `",
		STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
	return (-1);
}

int		ft_ari_syntax_error(char *input, char *token)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": syntax error in expression (error token is `",
		STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
	return (-1);
}

int		ft_ari_zero_divisor(char *input)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(input, STDERR_FILENO);
	ft_putstr_fd(": division by 0\n", STDERR_FILENO);
	return (-1);
}
