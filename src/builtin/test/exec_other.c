/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 04:56:57 by jolabour          #+#    #+#             */
/*   Updated: 2019/03/27 05:35:10 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			check_nbr(t_42sh *sh)
{
	int		i;

	i = 0;
	if (sh->argv->argv[1][i] == '-' || sh->argv->argv[1][i] == '+')
		i++;
	while (sh->argv->argv[1][i])
	{
		if (sh->argv->argv[1][i] > '9' || sh->argv->argv[1][i] < '0')
			return (1);
		i++;
	}
	i = 0;
	if (sh->argv->argv[3][i] == '-' || sh->argv->argv[3][i] == '+')
		i++;
	while (sh->argv->argv[3][i])
	{
		if (sh->argv->argv[3][i] > '9' || sh->argv->argv[3][i] < '0')
			return (3);
		i++;
	}
	return (0);
}

int			execute_other_opt(t_42sh *sh, char *str)
{
	const char			*option_tab_other[7] = {"=", "!=",
		"-eq", "-ne", "-ge", "-lt", "-le"};
	const t_ak			action_option_other[7] = {test_equal,
		test_diff, test_eq, test_ne, test_ge, test_lt, test_le};
	int					i;
	int					pos;

	i = -1;
	while (++i < 7)
	{
		if (ft_strequ(str, option_tab_other[i]) != 0)
		{
			if (i >= 2 && (pos = check_nbr(sh)) != 0)
			{
				ft_putstr_fd("test: integer expression expected: ", 2);
				ft_putendl_fd(sh->argv->argv[pos], 2);
				return (sh->retval = 2);
			}
			action_option_other[i](sh);
			return (1);
		}
	}
	ft_putstr_fd("42sh: condition expected: ", 2);
	ft_putendl_fd(sh->argv->argv[2], 2);
	return (sh->retval = 2);
}
