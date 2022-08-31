/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_lex_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:29:08 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:48:17 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				ft_ari_lex_hex(t_ari_lex *lex)
{
	size_t		i;

	if (lex->input[lex->index] == '0' && (lex->input[lex->index + 1] == 'x' ||
		lex->input[lex->index + 1] == 'X'))
	{
		i = 2;
		while (lex->input[lex->index + i] &&
			ft_strchr("0123456789ABCDEFabcdef", lex->input[lex->index + i]))
			i++;
		ft_ari_toklist_add(lex, ARI_HEX, i);
		return (1);
	}
	return (0);
}

int				ft_ari_lex_oct(t_ari_lex *lex)
{
	size_t		i;

	if (lex->input[lex->index] == '0')
	{
		i = 1;
		while (lex->input[lex->index + i] &&
			ft_strchr("01234567", lex->input[lex->index + i]))
			i++;
		ft_ari_toklist_add(lex, ARI_OCT, i);
		return (1);
	}
	return (0);
}

int				ft_ari_lex_dec(t_ari_lex *lex)
{
	size_t		i;

	if (lex->input[lex->index] &&
		ft_strchr("123456789", lex->input[lex->index]))
	{
		i = 1;
		while (lex->input[lex->index + i] &&
			ft_strchr("0123456789", lex->input[lex->index + i]))
			i++;
		ft_ari_toklist_add(lex, ARI_DEC, i);
		return (1);
	}
	return (0);
}
