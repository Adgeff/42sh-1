/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_lex_others.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:29:59 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:48:13 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				ft_ari_lex_op(t_ari_lex *lex)
{
	int			i;

	i = 0;
	while (g_arioptab[i].text && ft_strncmp(lex->input + lex->index,
		g_arioptab[i].text, ft_strlen(g_arioptab[i].text)))
		i++;
	if (g_arioptab[i].text)
	{
		ft_ari_toklist_add(lex, g_arioptab[i].token,
			ft_strlen(g_arioptab[i].text));
		return (1);
	}
	return (0);
}

int				ft_ari_lex_blank(t_ari_lex *lex)
{
	if (lex->input[lex->index] == ' ' || lex->input[lex->index] == '\t' ||
		lex->input[lex->index] == '\n')
	{
		lex->index++;
		return (1);
	}
	return (0);
}

int				ft_ari_lex_var(t_ari_lex *lex)
{
	size_t		i;

	if (ft_isalpha(lex->input[lex->index]) || lex->input[lex->index] == '_')
	{
		i = 1;
		while (ft_isalnum(lex->input[lex->index + i]) ||
			lex->input[lex->index + i] == '_')
			i++;
		ft_ari_toklist_add(lex, ARI_VAR, i);
		return (1);
	}
	return (0);
}

int				ft_ari_lex_illegal_char(t_ari_lex *lex)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(lex->input, STDERR_FILENO);
	ft_putstr_fd(": illegal character: ", STDERR_FILENO);
	ft_putchar_fd(lex->input[lex->index], STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (-1);
}
