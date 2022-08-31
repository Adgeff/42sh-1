/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_exe_pow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 05:00:11 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:44:43 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_ari_exe_pow(t_ari_node *node, int rec, t_42sh *shell)
{
	long	pow;

	if (g_ari_exetab[node->left->token](node->left, rec, shell) ||
		g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = 1;
	if ((pow = node->right->value) < 0)
		return (ft_ari_negative_exponent(node->input));
	while (pow)
	{
		node->value *= node->left->value;
		pow--;
	}
	return (0);
}
