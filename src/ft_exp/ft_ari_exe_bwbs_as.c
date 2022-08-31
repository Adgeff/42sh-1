/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_exe_bwbs_as.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:56:08 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:45:59 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_ari_exe_bw_and_as(t_ari_node *node, int rec, t_42sh *shell)
{
	if (ft_ari_exe_bw_and(node, rec, shell))
		return (-1);
	ft_ari_assign(node->left->text, node->value, shell);
	return (0);
}

int		ft_ari_exe_bw_or_as(t_ari_node *node, int rec, t_42sh *shell)
{
	if (ft_ari_exe_bw_or(node, rec, shell))
		return (-1);
	ft_ari_assign(node->left->text, node->value, shell);
	return (0);
}

int		ft_ari_exe_bw_xor_as(t_ari_node *node, int rec, t_42sh *shell)
{
	if (ft_ari_exe_bw_xor(node, rec, shell))
		return (-1);
	ft_ari_assign(node->left->text, node->value, shell);
	return (0);
}

int		ft_ari_exe_bs_lt_as(t_ari_node *node, int rec, t_42sh *shell)
{
	if (ft_ari_exe_bs_lt(node, rec, shell))
		return (-1);
	ft_ari_assign(node->left->text, node->value, shell);
	return (0);
}

int		ft_ari_exe_bs_rt_as(t_ari_node *node, int rec, t_42sh *shell)
{
	if (ft_ari_exe_bs_rt(node, rec, shell))
		return (-1);
	ft_ari_assign(node->left->text, node->value, shell);
	return (0);
}
