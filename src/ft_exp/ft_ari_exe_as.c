/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_exe_as.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 05:00:41 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:41:18 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_ari_assign(char *varname, long value, t_42sh *shell)
{
	char	*assign;
	char	*text_value;

	text_value = ft_lgtoa(value);
	assign = (char *)ft_malloc_exit((ft_strlen(varname) +
		ft_strlen(text_value) + 2) * sizeof(char));
	ft_strcpy(assign, varname);
	ft_strcat(assign, "=");
	ft_strcat(assign, text_value);
	free(text_value);
	check_local_variable(shell, assign);
	free(assign);
}

int			ft_ari_exe_as(t_ari_node *node, int rec, t_42sh *shell)
{
	if (g_ari_exetab[node->right->token](node->right, rec, shell))
		return (-1);
	node->value = (node->right->value);
	ft_ari_assign(node->left->text, node->value, shell);
	return (0);
}
