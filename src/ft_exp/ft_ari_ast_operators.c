/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_ast_operators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:40:53 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:46:45 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				ft_ari_ast_ps(t_ari_ast *ast)
{
	t_ari_node	*next;

	if (!ast->current ||
		(g_ari_asttab[ast->current->token].type & ARI_TYPE_OP))
	{
		next = ast->list->right;
		free(ast->list->text);
		free(ast->list);
		ast->list = next;
	}
	else
		return (ft_ari_ast_op(ast));
	return (0);
}

int				ft_ari_ast_ms(t_ari_ast *ast)
{
	if (!ast->current ||
		(g_ari_asttab[ast->current->token].type & ARI_TYPE_OP))
	{
		ast->list->token = ARI_MS_SIGN;
		ft_ari_ast_insert_child(ast);
	}
	else
		return (ft_ari_ast_op(ast));
	return (0);
}

int				ft_ari_ast_op(t_ari_ast *ast)
{
	if (!ast->current ||
		!(g_ari_asttab[ast->current->token].type & ARI_TYPE_VALUE))
		return (ft_ari_operand_expected(ast->input, ast->list->text));
	if (ast->current)
		while (ast->current->parent &&
			g_ari_asttab[ast->current->parent->token].priority >=
			g_ari_asttab[ast->list->token].priority)
			ast->current = ast->current->parent;
	ft_ari_ast_insert_parent(ast);
	return (0);
}

int				ft_ari_ast_as(t_ari_ast *ast)
{
	if (!ast->current)
		return (ft_ari_operand_expected(ast->input, ast->list->text));
	if (!(g_ari_asttab[ast->current->token].type & ARI_TYPE_VAR))
		return (ft_ari_non_variable(ast->input, ast->current->text));
	if (ast->current->parent &&
		!(g_ari_asttab[ast->current->parent->token].type & ARI_TYPE_SUB))
		return (ft_ari_non_variable(ast->input, ast->current->parent->text));
	ft_ari_ast_insert_parent(ast);
	return (0);
}

int				ft_ari_ast_db(t_ari_ast *ast)
{
	if (ast->current &&
		(g_ari_asttab[ast->current->token].type & ARI_TYPE_VAR))
	{
		if (ast->current->parent &&
				(g_ari_asttab[ast->current->parent->token].type & ARI_TYPE_DB))
			return (ft_ari_already_incrdecr(ast->input,
					ast->current->text, ast->list->text));
		else
		{
			ft_ari_ast_insert_parent(ast);
			ast->current = ast->current->left;
		}
	}
	else
		ft_ari_ast_insert_child(ast);
	return (0);
}
