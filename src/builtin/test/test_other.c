/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 05:36:10 by jolabour          #+#    #+#             */
/*   Updated: 2019/03/27 05:37:15 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		test_equal(t_42sh *sh)
{
	if (ft_strequ(sh->argv->argv[1], sh->argv->argv[3]) == 1)
		sh->retval = 0;
	else
		sh->retval = 1;
}

void		test_diff(t_42sh *sh)
{
	if (ft_strequ(sh->argv->argv[1], sh->argv->argv[3]) == 1)
		sh->retval = 1;
	else
		sh->retval = 0;
}

void		test_eq(t_42sh *sh)
{
	int		tmp;
	int		tmp2;

	tmp = ft_atoi(sh->argv->argv[1]);
	tmp2 = ft_atoi(sh->argv->argv[3]);
	if (tmp == tmp2)
		sh->retval = 0;
	else
		sh->retval = 1;
}

void		test_ne(t_42sh *sh)
{
	int		tmp;
	int		tmp2;

	tmp = ft_atoi(sh->argv->argv[1]);
	tmp2 = ft_atoi(sh->argv->argv[3]);
	if (tmp != tmp2)
		sh->retval = 0;
	else
		sh->retval = 1;
}

void		test_ge(t_42sh *sh)
{
	int		tmp;
	int		tmp2;

	tmp = ft_atoi(sh->argv->argv[1]);
	tmp2 = ft_atoi(sh->argv->argv[3]);
	if (tmp >= tmp2)
		sh->retval = 0;
	else
		sh->retval = 1;
}
