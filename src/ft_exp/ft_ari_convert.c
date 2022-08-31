/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:36:54 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:47:04 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			ft_ari_node_add(t_ari_ast *ast, t_aritok token,
				char *text, long value)
{
	t_ari_node	*new;

	new = (t_ari_node *)ft_malloc_exit(sizeof(t_ari_node));
	*new = (t_ari_node){token, text, value, ast->input, NULL, NULL, NULL, 0};
	if (ast->current)
		ast->current->right = new;
	else
		ast->list = new;
	ast->current = new;
}

void			ft_ari_convert_lex(t_ari_lex *lex, t_ari_ast *ast)
{
	lex->current = lex->begin;
	while (lex->current)
	{
		g_ari_asttab[lex->current->token].conv(ast, lex->current, lex->input);
		lex->current = lex->current->next;
	}
	ft_ari_lex_free(lex->begin);
	ast->current = NULL;
}
