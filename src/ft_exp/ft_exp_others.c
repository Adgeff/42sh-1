/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:29:55 by geargenc          #+#    #+#             */
/*   Updated: 2019/04/12 14:30:22 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_exp_text(t_txtlist *txt, t_42sh *shell)
{
	(void)shell;
	txt->data = ft_strsub(txt->data, txt->start, txt->len);
	return (0);
}

int			ft_exp_var(t_txtlist *txt, t_42sh *shell)
{
	char	*var;

	if (txt->len == 1)
		return (ft_exp_text(txt, shell));
	var = ft_strsub(txt->data, txt->start + 1, txt->len - 1);
	txt->data = ft_getvar(var, shell);
	free(var);
	txt->data = txt->data ? ft_backslash_quotes(txt->data, txt->dquote)
		: ft_strdup("");
	return (0);
}

int			ft_exp_expr(t_txtlist *txt, t_42sh *shell)
{
	char	*exp;

	txt->data = ft_strsub(txt->data, txt->start + 3, txt->len - 5);
	exp = ft_simple_expanse(txt->data, shell);
	free(txt->data);
	if (!(txt->data = ft_exp_ary(exp, shell)))
		return (-1);
	return (0);
}
