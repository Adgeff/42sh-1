/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_exe_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:57:17 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:43:04 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_ari_exe_db_ps(t_ari_node *node, int rec, t_42sh *shell)
{
	if (node->left)
	{
		if (g_ari_exetab[node->left->token](node->left, rec, shell))
			return (-1);
		node->value = node->left->value;
		ft_ari_assign(node->left->text, node->value + 1, shell);
	}
	else
	{
		if (g_ari_exetab[node->right->token](node->right, rec, shell))
			return (-1);
		node->value = node->right->value + 1;
		ft_ari_assign(node->right->text, node->value, shell);
	}
	return (0);
}

int		ft_ari_exe_db_ms(t_ari_node *node, int rec, t_42sh *shell)
{
	if (node->left)
	{
		if (g_ari_exetab[node->left->token](node->left, rec, shell))
			return (-1);
		node->value = node->left->value;
		ft_ari_assign(node->left->text, node->value - 1, shell);
	}
	else
	{
		if (g_ari_exetab[node->right->token](node->right, rec, shell))
			return (-1);
		node->value = node->right->value - 1;
		ft_ari_assign(node->right->text, node->value, shell);
	}
	return (0);
}
