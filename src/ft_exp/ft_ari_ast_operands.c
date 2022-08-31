/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_ast_operands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:41:51 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:46:25 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				ft_ari_ast_value(t_ari_ast *ast)
{
	if (ast->current &&
		!(g_ari_asttab[ast->current->token].type & ARI_TYPE_OP))
		return (ft_ari_syntax_error(ast->input, ast->list->text));
	ft_ari_ast_insert_child(ast);
	return (0);
}

int				ft_ari_ast_par_rt(t_ari_ast *ast)
{
	t_ari_node	*next;

	if (!ast->current ||
		(g_ari_asttab[ast->current->token].type & ARI_TYPE_OP))
		return (ft_ari_operand_expected(ast->input, ast->list->text));
	while (ast->current &&
		!(g_ari_asttab[ast->current->token].type & ARI_TYPE_SUB))
		ast->current = ast->current->parent;
	if (ast->current)
	{
		next = ast->list->right;
		free(ast->list->text);
		free(ast->list);
		ast->list = next;
		ast->current->token = ARI_PAR_RT;
	}
	else
		return (ft_ari_syntax_error(ast->input, ast->list->text));
	return (0);
}
