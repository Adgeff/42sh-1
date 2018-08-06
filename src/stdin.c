/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:09:06 by jolabour          #+#    #+#             */
/*   Updated: 2018/08/06 05:12:09 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "sh.h"

int			check_input(unsigned char *input, t_42sh *sh)
{
	if (UP_KEY)
		return (1);
	else if (DOWN_KEY)
		return (1);
	else if (TAB)
		return (1);
//	else if (OPT_B)
//	{
//		move_to_begin_word(sh);
//		return (1);
//	}
//	else if (OPT_F)
//	{
//		move_to_end_word(sh);
//		return (1);
//	}
	else if (RIGHT_KEY)
	{
		move_to_right(sh);
		return (1);
	}
	else if (LEFT_KEY)
	{
		move_to_left(sh);
		return (1);
	}
	else if (HOME)
	{
		move_to_start(sh);
		return (1);
	}
	else if (END)
	{
		move_to_end(sh);
		return (1);
	}
	else if (CTRL_D)
		exit(EXIT_SUCCESS);
	else if (CTRL_C)
	{
		ft_putchar('\n');
		return (-1);
	}
	else if (DEL)
	{
		delete_input(sh);
		return (1);
	}
	return (0);
}

int					get_line(t_42sh *sh)
{
	int				i;
	unsigned char	buf[7];

	ft_bzero(sh->input, 256);
	sh->line_pos = 0;
	sh->len_line = 0;
	while (42)
	{
		if ((i = read(0, buf, 6)) > 0)
		{
			buf[i] = '\0';
			if (buf[0] == '\n')
			{
				ft_putchar('\n');
				insert_mode_off();
				return (1);
			}
			if ((i = check_input(buf, sh)) != 1)
			{
				if (i == -1)
					return (0);
				printf("%s", (char *)buf);
				add_char(buf, sh);
			}
		}
	}
}
