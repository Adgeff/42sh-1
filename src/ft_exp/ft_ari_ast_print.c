/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_ast_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:45:32 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:46:48 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			ft_ari_ast_getsize(t_ari_node *node)
{
	if (node)
	{
		ft_ari_ast_getsize(node->left);
		ft_ari_ast_getsize(node->right);
		if (node->left)
			node->size = node->left->size;
		if (node->right && node->right->size > node->size)
			node->size = node->right->size;
		if (node->size)
			node->size = node->size * 2 + 2;
		else
			node->size = 13;
	}
}

void			ft_ari_ast_getspace(t_ari_node *node)
{
	if (node)
	{
		if (node->parent)
			node->size = node->parent->size / 2;
		ft_ari_ast_getspace(node->left);
		ft_ari_ast_getspace(node->right);
	}
}

void			ft_ari_ast_getpos(t_ari_node *node, unsigned int jump)
{
	if (node)
	{
		node->size = jump * node->size + (node->size - 13) / 2;
		ft_ari_ast_getpos(node->left, jump * 2);
		ft_ari_ast_getpos(node->right, jump * 2 + 1);
	}
}

size_t			ft_ari_ast_print_level(t_ari_node *node, unsigned int level,
				size_t written)
{
	if (node)
	{
		if (level)
		{
			written = ft_ari_ast_print_level(node->left, level - 1, written);
			written = ft_ari_ast_print_level(node->right, level - 1, written);
		}
		else
		{
			if (written < node->size)
				written = written + printf("%*c",
					(int)(node->size - written), ' ');
			written = written + printf("%13s", g_aritoktab[node->token]);
		}
	}
	return (written);
}

void			ft_ari_ast_print(t_ari_ast *ast)
{
	size_t			total_size;
	unsigned int	i;
	size_t			ret;

	if (ast->begin)
	{
		ft_ari_ast_getsize(ast->begin);
		total_size = ast->begin->size;
		ft_ari_ast_getspace(ast->begin);
		ft_ari_ast_getpos(ast->begin, 0);
		i = 0;
		while ((ret = ft_ari_ast_print_level(ast->begin, i, 0)))
		{
			if (ret < total_size)
				printf("%*c", (int)(total_size - ret), ' ');
			printf("|\n\n");
			i++;
		}
	}
}
