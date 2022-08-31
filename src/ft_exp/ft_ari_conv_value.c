/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ari_conv_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 04:34:45 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/31 12:47:00 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			ft_ari_conv_dec(t_ari_ast *ast, t_ari_toklist *current,
				char *input)
{
	long		value;
	size_t		i;

	value = 0;
	i = 0;
	while (i < current->len)
	{
		value *= 10;
		value += input[current->begin + i] - '0';
		i++;
	}
	ft_ari_node_add(ast, current->token,
		ft_strsub(input, current->begin, current->len), value);
}

void			ft_ari_conv_hex(t_ari_ast *ast, t_ari_toklist *current,
				char *input)
{
	long		value;
	size_t		i;

	value = 0;
	i = 2;
	while (i < current->len)
	{
		value *= 16;
		if (ft_isdigit(input[current->begin + i]))
			value += input[current->begin + i] - '0';
		else
			value += ft_tolower(input[current->begin + i]) - 'a' + 10;
		i++;
	}
	ft_ari_node_add(ast, current->token,
		ft_strsub(input, current->begin, current->len), value);
}

void			ft_ari_conv_oct(t_ari_ast *ast, t_ari_toklist *current,
				char *input)
{
	long		value;
	size_t		i;

	value = 0;
	i = 0;
	while (i < current->len)
	{
		value *= 8;
		value += input[current->begin + i] - '0';
		i++;
	}
	ft_ari_node_add(ast, current->token,
		ft_strsub(input, current->begin, current->len), value);
}
