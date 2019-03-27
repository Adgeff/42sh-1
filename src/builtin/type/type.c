/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 05:37:41 by jolabour          #+#    #+#             */
/*   Updated: 2019/03/27 05:57:40 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*check_is_alias(t_42sh *sh, char *str)
{
	int		i;
	t_alias	*start;
	char	*to_return;

	i = 0;
	start = sh->alias->begin;
	if (sh->alias->size == 0)
		return (NULL);
	while (i < sh->alias->size)
	{
		if (ft_strequ(start->to_sub, str) == 1)
		{
			to_return = ft_strdup(start->sub);
			return (to_return);
		}
		start = start->next;
		i++;
	}
	return (NULL);
}

int			check_is_builtin(t_42sh *sh, char *str)
{
	int		i;

	i = 0;
	while (sh->builtin[i])
	{
		if (ft_strequ(sh->builtin[i], str) == 1)
			return (1);
		i++;
	}
	return (0);
}

void		get_type(t_42sh *sh)
{
	int				i;
	char			*to_print;
	BUCKET_CONTENT	*bucket_entry;

	i = 0;
	while (++i < sh->argv->size)
	{
		if ((to_print = check_is_alias(sh, sh->argv->argv[i])) != NULL)
		{
			print_type_alias(sh, i, to_print);
			ft_strdel(&to_print);
		}
		else if (check_is_builtin(sh, sh->argv->argv[i]) == 1)
			print_type_builtin(sh, i);
		else if ((bucket_entry = ht_lookup(sh->argv->argv[0],
					&sh->hashtable)) != NULL)
			print_type_hash(sh, i, bucket_entry->path);
		else if ((to_print = check_access(sh, i)) != NULL)
		{
			print_type_binary(sh, i, to_print);
			ft_strdel(&to_print);
		}
		else
			print_type_error(sh, i);
	}
}

void		builtin_type(t_42sh *sh)
{
	if (sh->argv->size == 1)
		sh->retval = 0;
	else
		get_type(sh);
}
