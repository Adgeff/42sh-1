/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 07:47:49 by jolabour          #+#    #+#             */
/*   Updated: 2018/08/04 03:38:46 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			process(t_42sh *sh)
{
	prompt(sh->env);
	if (get_line(sh) != 1)
		return ;
	return ;
}
