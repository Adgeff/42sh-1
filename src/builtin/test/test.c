#include "sh.h"

const char			option_tab[OPTION_TEST] = {'b', 'c', 'd', 'e', 'f', 'g', 'L', 'p', 'r', 'S', 's', 'u', 'w', 'x', 'z'};

const t_test			action_option[OPTION_TEST] = {test_b, test_c, test_d, test_e, test_f, test_g, test_L, test_p, test_r, test_S, test_s, test_u, test_w, test_x, test_z};

int			execute_test(t_42sh *sh, char c)
{
	int		i;
	struct stat info;

	i = 0;
	while (i < OPTION_TEST)
	{
		if (option_tab[i] == c)
		{
			if (stat(sh->argv->argv[2], &info) != 0 && sh->argv->argv[1][2] != 'z')
				return (0);
			action_option[i](sh, info);
			return (1);
		}
		i++;
	}
	return (0);
}

int			check_option(t_42sh *sh)
{
	int		i;

	if (ft_strlen(sh->argv->argv[1]) != 2 || sh->argv->argv[1][0] != '-')
		return (0);
	if ((i = execute_test(sh, sh->argv->argv[1][1])) == 0)
		return (0);
	return (1);
}

void		builtin_test(t_42sh *sh)
{
	sh->argv->error_code = 1;
	if (sh->argv->size == 3)
	{
		if (check_option(sh) == 0)
			sh->argv->error_code = 1;
	}
	/*if (sh->argv->size == 4)
	{
		if (sh->argv->argv[2][0] != '-')
		{
			sh->argv->error_code = 1;
			return (0);
		}
		if ((i = check_option(sh)) == 0)
		{
			sh->argv->error_code = 1;
			return ;
		}
	}*/
}
