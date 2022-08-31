/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:28:31 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 13:44:57 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				ft_ari_ast_free_return(t_ari_ast *ast, int ret)
{
	ft_ari_ast_free(ast->begin);
	ft_ari_ast_free(ast->list);
	return (ret);
}

int				ft_ari(char *expr, long *res, int rec, t_42sh *shell)
{
	t_ari_lex	lex;
	t_ari_ast	ast;

	lex = (t_ari_lex){expr, 0, NULL, NULL};
	if (ft_ari_lexer(&lex))
		return (-1);
	ast = (t_ari_ast){expr, NULL, NULL, NULL};
	ft_ari_convert_lex(&lex, &ast);
	if (ft_ari_ast(&ast))
		return (ft_ari_ast_free_return(&ast, -1));
	*res = 0;
	if (ast.begin)
	{
		if (g_ari_exetab[ast.begin->token](ast.begin, rec, shell))
			return (ft_ari_ast_free_return(&ast, -1));
		*res = ast.begin->value;
	}
	return (ft_ari_ast_free_return(&ast, 0));
}
