/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 03:52:33 by jolabour          #+#    #+#             */
/*   Updated: 2019/03/27 03:56:15 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			print_export(t_42sh *sh)
{
	int			i;

	i = 0;
	while (sh->copy_env[i])
	{
		ft_putstr("export ");
		ft_putendl(sh->copy_env[i]);
		i++;
	}
}

void			print_error_export(t_42sh *sh, int i)
{
	ft_putstr_fd("42sh: export: ", 2);
	ft_putstr_fd(sh->argv->argv[i], 2);
	ft_putendl_fd(": invalid option", 2);
	sh->retval = 1;
}
