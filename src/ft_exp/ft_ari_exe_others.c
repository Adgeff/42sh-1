/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_exe_others.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 05:01:39 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:44:03 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_ari_exe_value(t_ari_node *node, int rec, t_42sh *shell)
{
	(void)rec;
	(void)node;
	(void)shell;
	return (0);
}

int			ft_ari_exe_var(t_ari_node *node, int rec, t_42sh *shell)
{
	char					*var;

	if (rec >= FT_ARI_MAX_REC)
		return (ft_ari_recursion_exceeded(node->input, node->text));
	var = ft_getvar(node->text, shell);
	if (var && ft_ari(var, &node->value, rec + 1, shell))
	{
		free(var);
		return (-1);
	}
	else if (var)
		free(var);
	return (0);
}

int			ft_ari_exe_par_rt(t_ari_node *node, int rec, t_42sh *shell)
{
	(void)shell;
	if (g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = (node->right->value);
	return (0);
}

int			ft_ari_exe_ms_sign(t_ari_node *node, int rec, t_42sh *shell)
{
	(void)shell;
	if (g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = (-node->right->value);
	return (0);
}
