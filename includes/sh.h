/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 04:26:44 by jolabour          #+#    #+#             */
/*   Updated: 2018/12/02 22:24:42 by jolabour         ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <stdio.h>
# include "libft.h"


# define NB_INPUT_SELECT 7
# define NB_INPUT 12
# define RIGHT_KEY 4414235
# define LEFT_KEY 4479771
# define HOME 4741915
# define END 4610843
# define CTRL_C 3
# define CTRL_D 4
# define DEL 127
# define UP_KEY 4283163
# define DOWN_KEY 4348699
# define TAB 9
# define OPT_B 11241698
# define OPT_F 37574
# define OPT_C 42947
# define OPT_X 8948194
# define OPT_V 10127586

# define SET_FG_RED		"\x1b[38;5;196m"
# define RESET_COLOR	"\x1b[0m"

# ifdef MINISHELL
#  define PROG_NAME "minishell"
# elif defined _21SH
#  define PROG_NAME "21sh"
# else
#  define PROG_NAME "21sh"
# endif

/*
** }}}
*/

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

# define BUCKET_CONTENT	t_bucket_content

typedef struct		s_bucket_content
{
	struct s_bucket_content	*next;
	char					*name;
	char					*path;
	size_t					pathlen;
}					BUCKET_CONTENT;

# define BUCKET	t_bucket
typedef struct		s_bucket
{
	BUCKET_CONTENT	*first;
	uint8_t			length;
}					BUCKET;

typedef struct 		s_ht
{
# define INITIAL_HASHTABLE_SIZE (1U << 9)
	BUCKET		buckets[INITIAL_HASHTABLE_SIZE];
	uint16_t	used;
	uint16_t	capacity;
}					t_ht;

typedef struct termios	t_term;

typedef struct		s_stdin
{
	int				line_pos;
	int				len_line;
	char			*str_to_paste;
	int				nb_line;
	int				start_und;
	int				end_und;
	int				ctrlc;
	int				cursor_pos;
	int				save_pos;
}					t_stdin;

typedef struct		s_42sh
{
	char			input[1000];
	char			**tokens;
	char			*valide_path;
	int				winsize;
	int				prompt_len;
	char			*pwd;
	char			**bin_dirs;
	char			**copy_env;
	t_stdin			*stdin;
	t_env			*env;
	t_term			term;
	t_ht			hashtable;
}					t_42sh;

typedef				void(*t_ak)(t_42sh *sh);

/*****************************************************************************\
|                               SELECT_MODE                                   |
\*****************************************************************************/

/*
** select_mode
*/

void				select_mode(t_42sh *sh);
void				clean_print_select(t_42sh *sh);

/*
** keymap_select
*/

int					check_input_select(t_42sh *sh, long buf);

/*
** move_select_mode
*/

void				move_to_right_select(t_42sh *sh);
void				move_to_left_select(t_42sh *sh);

/*
** exit_select_mode
*/

void				exit_select_mode(t_42sh *sh, int pos);

/*
** action_select_mode
*/

void				copy_select(t_42sh *sh);
void				del_select(t_42sh *sh);
void				cut_select(t_42sh *sh);

/*****************************************************************************\
|                               LINE_EDITION                                  |
\*****************************************************************************/

/*
** stdin
*/

int				get_line(t_42sh *sh);
int				get_winsize(void);
void			ft_paste(t_42sh *sh);
void			clean_print(t_42sh *sh);
int				get_curent_line(t_42sh *sh);

/*
** check_input
*/

int				check_input(t_42sh *sh, long buf);

/*
** control_action
*/

void			ctrlc_action(t_42sh *sh);
void			ctrld_action(t_42sh *sh);
void			paste(t_42sh *sh);

/*
** insert_mode
*/

void				insert_mode_on(void);
void				insert_mode_off(void);

/*
** manip_input
*/

void				add_char(long input, t_42sh *sh);
void				delete_char(t_42sh *sh);
void				delete_input(t_42sh *sh);
void				delete_input_buf(t_42sh *sh);
void				delete_cut(t_42sh *sh);
void				delete_after_cursor(t_42sh *sh);
void				delete(void);

/*
** process
*/

void				process(t_42sh *sh);

/*
** move_arrows
*/

int					putchar_custom(int c);
void				move_to_right(t_42sh *sh);
void				move_to_left(t_42sh *sh);
void				move_to_start(t_42sh *sh);
void				move_to_end(t_42sh *sh);

/*
** move_word
*/

void				move_to_begin_word(t_42sh *sh);
void				move_to_end_word(t_42sh *sh);

/*
** move_line
*/

void				move_down(t_42sh *sh);

/*****************************************************************************\
|                                  PROCESS                                    |
\*****************************************************************************/

/*
 ** process
 */

void			process(t_42sh *sh);

/*
** prompt
*/

void			prompt(t_env *list, t_42sh *sh);

/*
** hash_table
*/

BUCKET_CONTENT	*ht_lookup(const char *s, t_ht *ht);
BUCKET_CONTENT	*ht_insert(const char *path, const char *name, t_ht *ht);
void			ht_delete(const char *name, t_ht *ht);
void			init_hashtable(t_42sh *sh);
void			print_hashtable(t_ht ht);

/*****************************************************************************\
|                               INIT_SHELL                                    |
\*****************************************************************************/

/*
** list
*/

int					len_list(t_env *env);
char				**list_to_tab(t_env *env, char **copy_env);
t_env				*create_node(char *str);
void				lst_push(t_env **head, t_env *new);
t_env				*set_list(char **env);

/*
** getenv
*/

char				*ft_getenv(t_env *list, const char *name, size_t len);

/*
** init_shell
*/

void				get_term(t_42sh *sh);
void				init_shell(t_42sh *sh, char **env);
int					get_line(t_42sh *sh);

/*
**  ERROR
*/

/*
** errno
*/

void				init_error_tab(void);
void				print_error(int code, bool is_fatal);
void				print_error_and_exit(int error_code);
void				print_error_first(int error_code);
int					ft_set_errno(int n);

/*
** Utils
*/

char				*ft_joinpath(const char *path, const char *name);

void				print_env_array(char **env);

#endif
