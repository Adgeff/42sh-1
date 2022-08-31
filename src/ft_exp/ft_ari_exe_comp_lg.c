/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_exe_comp_lg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:53:02 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:42:52 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_ari_exe_lt(t_ari_node *node, int rec, t_42sh *shell)
{
	(void)shell;
	if (g_ari_exetab[node->left->token](node->left, rec, shell) ||
		g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = (node->left->value < node->right->value);
	return (0);
}

int		ft_ari_exe_gt(t_ari_node *node, int rec, t_42sh *shell)
{
	(void)shell;
	if (g_ari_exetab[node->left->token](node->left, rec, shell) ||
		g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = (node->left->value > node->right->value);
	return (0);
}

int		ft_ari_exe_le(t_ari_node *node, int rec, t_42sh *shell)
{
	(void)shell;
	if (g_ari_exetab[node->left->token](node->left, rec, shell) ||
		g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = (node->left->value <= node->right->value);
	return (0);
}

int		ft_ari_exe_ge(t_ari_node *node, int rec, t_42sh *shell)
{
	(void)shell;
	if (g_ari_exetab[node->left->token](node->left, rec, shell) ||
		g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = (node->left->value >= node->right->value);
	return (0);
}
