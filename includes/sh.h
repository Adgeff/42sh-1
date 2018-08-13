/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 04:26:44 by jolabour          #+#    #+#             */
/*   Updated: 2018/08/13 03:01:47 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <sys/wait.h>
# include <signal.h>
# include <term.h>
# include <curses.h>
# include <pwd.h>
# include <termios.h>
# include "libft.h"

# define RIGHT_KEY(x) ((x)[0] == 27 && (x)[2] == 'C')
# define LEFT_KEY(x) ((x)[0] == 27 && (x)[2] == 'D')
# define HOME(x) ((x)[0] == 27 && (x)[2] == 'H')
# define END(x) ((x)[0] == 27 && (x)[2] == 'F')
# define CTRL_C(x) ((x)[0] == 3)
# define CTRL_D(x) ((x)[0] == 4)
# define DEL(x) ((x)[0] == 127)
# define UP_KEY(x) ((x)[0] == 27 && (x)[2] == 'A')
# define DOWN_KEY(x) ((x)[0] == 27 && (x)[2] == 'B')
# define TAB(x) ((x)[0] == 9)
# define OPT_B(x) ((x)[0] == 226 && (x)[1] == 136 && (x)[2] == 171)
# define OPT_F(x) ((x)[0] == 198 && (x)[1] == 146)
# define OPT_C(x) ((x)[0] == 0xC3 && (x)[1] == 0xA7)
# define OPT_X(x) ((x)[0] == 226 && (x)[1] == 137 && (x)[2] == 136)
# define OPT_V(x) ((x)[0] == 0xE2 && (x)[1] == 136 && (x)[2] == 0x9A)
# define PAGE_DOWN(x) ((x)[0] == 27 && (x)[2] == '6' && (x)[3] == '~')

# define SET_FG_RED		"\x1b[38;5;196m"
# define RESET_COLOR	"\x1b[0m"

typedef enum		e_errno_val
{
	_ENOMEM = 1,
	_ENAMETOOLONG,
	_ENOENV,
	_ENAMEENV,
	_ENOHOME,
	_ENOUSER,
	_ENOVAR,
	_ENOCMD,
	_ELOOP,
	_ENOTDIR,
	_EINVAL,
	_ENOENT,
	_ENOX,
	_ERRNO_VALUES
}					t_errno;

static t_errno		g_errno;
static const char	*g_errors[_ERRNO_VALUES];

typedef struct		s_env
{
	char			*str;
	struct s_env	*next;
}					t_env;

typedef struct termios	t_term;

typedef struct		s_42sh
{
	char			input[256];
	char			**arg;
	char			*pwd;
	char			**bin_dirs;
	char			**copy_env;
	t_env			*env;
	t_term			term;
	char			*str_to_paste;
	int				line_pos;
	int				len_line;
}					t_42sh;

/*
** errno
*/

void				init_error_tab(void);
void				print_error(int error_code);
void				print_error_and_exit(int error_code);
void				print_error_first(int error_code);
int					ft_set_errno(int n);

/*
** insert_mode
*/

void				insert_mode_on(void);
void				insert_mode_off(void);

/*
** select_mode
*/

void				select_mode(t_42sh *sh);

/*
** manip_input
*/

void				add_char(unsigned char input, t_42sh *sh);
void				delete_char(t_42sh *sh);
void				delete_input(t_42sh *sh);
void				delete_input_buf(t_42sh *sh);
void				delete_cut(t_42sh *sh);

/*
 ** process
 */

void			process(t_42sh *sh);

/*
** move_arrows
*/

int				putchar_custom(int c);
void			move_to_right(t_42sh *sh);
void			move_to_left(t_42sh *sh);
void			move_to_start(t_42sh *sh);
void			move_to_end(t_42sh *sh);

/*
** move_word
*/

void				move_to_begin_word(t_42sh *sh);
void				move_to_end_word(t_42sh *sh);

/*
** move_line
*/

void				move_down(t_42sh *sh);

/*
** prompt
*/

void			prompt(t_env *list);

/*
 ** list
 */

int				len_list(t_env *env);
void			list_to_tab(t_env *env, char **copy_env);
t_env			*create_node(char *str);
void			lst_push(t_env **head, t_env *new);
t_env			*set_list(char **env);

/*
 ** getenv
 */

char			*ft_getenv(t_env *list, const char *name, size_t len);

/*
** stdin
*/

int				get_line(t_42sh *sh);

/*
** init_shell
*/

void			get_term(t_42sh *sh);
void			init_shell(t_42sh *sh, char **env);

#endif
