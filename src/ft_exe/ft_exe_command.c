/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:49:16 by geargenc          #+#    #+#             */
/*   Updated: 2022/08/25 18:09:21 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char				*ft_exe_command_get_path(t_42sh *shell)
{
	int				i;
	char			*path;

	path = NULL;
	if (shell->bin_dirs)
	{
		free_tab(shell->bin_dirs);
		shell->bin_dirs = NULL;
	}
	i = 0;
	while (shell->copy_env[i])
	{
		if (ft_strncmp(shell->copy_env[i], "PATH=", 5) == 0)
			path = ft_strdup(shell->copy_env[i] + 5);
		i++;
	}
	if (path == NULL)
		path = get_var(shell, "PATH");
	if (path != NULL)
	{
		shell->bin_dirs = ft_strsplit(path, ':');
		ft_strdel(&path);
	}
	return (path);
}

void				get_path_ht(t_42sh *shell)
{
	BUCKET_CONTENT	*bucket_entry;

	if ((bucket_entry = ht_lookup(shell->argv->argv[0],
		&shell->hashtable)) != NULL)
	{
		shell->valide_path = ft_strdup(bucket_entry->path);
		if (access(shell->valide_path, F_OK) != 0
				|| access(shell->valide_path, X_OK) != 0)
			reset_hashtable(&shell->hashtable);
		ft_strdel(&shell->valide_path);
		shell->valide_path = check_access(shell, 0);
	}
	else
		shell->valide_path = check_access(shell, 0);
}

int					ft_exe_command_ht(t_node *current, t_42sh *shell)
{
	if (shell->argv->argv[0] && shell->argv->argv[0][0])
	{
		ft_exe_command_get_path(shell);
		get_path_ht(shell);
		if (shell->valide_path)
			ht_insert(shell->valide_path, shell->argv->argv[0],
					&shell->hashtable);
		else
			shell->valide_path = ft_strdup(shell->argv->argv[0]);
	}
	else if (shell->argv->argv[0])
		shell->valide_path = ft_strdup("");
	else
		shell->valide_path = NULL;
	return (ft_exe_file(current, shell, shell->valide_path, shell->argv->argv));
}

int					ft_exe_command(t_node *current, t_42sh *shell)
{
	void			*exe;

	if (!(shell->argv->argv = ft_command_to_args(current, shell)))
		shell->retval = 1;
	else if (ft_assigns(current, shell))
		shell->retval = 1;
	else if (shell->argv->argv[0] && (exe = ft_isbuiltin(shell->argv->argv[0])))
		shell->retval = ft_exe_builtin(current, shell, exe);
	else if (shell->argv->argv[0] && ft_strchr(shell->argv->argv[0], '/'))
		shell->retval = ft_exe_file(current, shell,
			ft_strdup(shell->argv->argv[0]), shell->argv->argv);
	else if (shell->argv->argv[0])
		shell->retval = ft_exe_command_ht(current, shell);
	if (shell->argv->argv)
		ft_free_split(shell->argv->argv);
	return (shell->retval);
}
