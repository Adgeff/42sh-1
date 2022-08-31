/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_conv_others.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:36:07 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:46:57 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			ft_ari_conv_var(t_ari_ast *ast, t_ari_toklist *current,
				char *input)
{
	ft_ari_node_add(ast, current->token,
		ft_strsub(input, current->begin, current->len), 0);
}

void			ft_ari_conv_op(t_ari_ast *ast, t_ari_toklist *current,
				char *input)
{
	(void)input;
	ft_ari_node_add(ast, current->token,
		ft_strsub(input, current->begin, current->len), 0);
}

void			ft_ari_conv_dbp(t_ari_ast *ast, t_ari_toklist *current,
				char *input)
{
	(void)input;
	if ((ast->current && (g_ari_asttab[ast->current->token].type &
		ARI_TYPE_VAR)) || (current->next &&
		(g_ari_asttab[current->next->token].type & ARI_TYPE_VAR)))
		ft_ari_node_add(ast, current->token,
			ft_strsub(input, current->begin, current->len), 0);
	else
	{
		ft_ari_node_add(ast, ARI_PS, ft_strdup("+"), 0);
		if (current->next && current->next->token == ARI_PS &&
			current->begin + current->len == current->next->begin)
		{
			current->next->token = ARI_DB_PS;
			current->next->begin--;
			current->next->len++;
		}
		else
			ft_ari_node_add(ast, ARI_PS, ft_strdup("+"), 0);
	}
}

void			ft_ari_conv_dbm(t_ari_ast *ast, t_ari_toklist *current,
				char *input)
{
	(void)input;
	if ((ast->current && (g_ari_asttab[ast->current->token].type &
		ARI_TYPE_VAR)) || (current->next &&
		(g_ari_asttab[current->next->token].type & ARI_TYPE_VAR)))
		ft_ari_node_add(ast, current->token,
			ft_strsub(input, current->begin, current->len), 0);
	else
	{
		ft_ari_node_add(ast, ARI_MS, ft_strdup("-"), 0);
		if (current->next && current->next->token == ARI_MS &&
			current->begin + current->len == current->next->begin)
		{
			current->next->token = ARI_DB_MS;
			current->next->begin--;
			current->next->len++;
		}
		else
			ft_ari_node_add(ast, ARI_MS, ft_strdup("-"), 0);
	}
}
