/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:13:10 by jolabour          #+#    #+#             */
/*   Updated: 2019/04/10 06:27:39 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		print_env_array(char **envp)
{
	unsigned int	i;

	i = 0;
	while (envp[i] != NULL)
		ft_putendl(envp[i++]);
}
