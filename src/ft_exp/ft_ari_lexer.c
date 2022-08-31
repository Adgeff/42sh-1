/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:31:52 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:48:21 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				ft_ari_toklist_add(t_ari_lex *lex, t_aritok token,
					size_t len)
{
	t_ari_toklist	*new;

	new = (t_ari_toklist *)ft_malloc_exit(sizeof(t_ari_toklist));
	*new = (t_ari_toklist){token, lex->index, len, NULL};
	lex->index += len;
	if (lex->current)
		lex->current->next = new;
	else
		lex->begin = new;
	lex->current = new;
}

void				ft_ari_lex_free(t_ari_toklist *begin)
{
	t_ari_toklist	*next;

	while (begin)
	{
		next = begin->next;
		free(begin);
		begin = next;
	}
}

int					ft_ari_lexer(t_ari_lex *lex)
{
	int			i;
	int			ret;

	while (lex->input[lex->index])
	{
		i = 0;
		while ((ret = g_ari_condtab[i](lex)) == 0)
			i++;
		if (ret == -1)
		{
			ft_ari_lex_free(lex->begin);
			return (-1);
		}
	}
	return (0);
}
