/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/24 15:40:39 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	shlvl(t_minish *minish)
{
	int		n;
	char	*temp;

	n = 0;
	src_in_list(&minish->env_list, "SHLVL");
	get_value(minish, minish->env_list->box);
	temp = ft_strtrim(minish->value, "\"");
	n = a_(temp, 10);
	freestr(temp);
	minish->temporary = ft_itoa(++n);
	freestr(minish->env_list->box);
	minish->env_list->box = ft_strjoin(ft_strdup("SHLVL="), minish->temporary);
	freestr(minish->temporary);
}

void	sub_init(t_minish *minish)
{
	minish->skipper = NULL;
	minish->len = 0;
	minish->double_q = 0;
	minish->single_q = 0;
	minish->cmd = NULL;
	minish->built_flag = 0;
	minish->status = 0;
	minish->cmd_arr = NULL;
	minish->pwd = NULL;
	minish->cd_flag = 0;
	minish->input = NULL;
	minish->key = NULL;
	minish->value = NULL;
	minish->env_to_search = NULL;
	minish->valid_flag = 1;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTSTP, signal_handler);
}

void	ft_ctrlc(char **envp)
{
	char	*argv[3];
	int		pid;

	argv[0] = ft_strdup("stty");
	argv[1] = ft_strdup("-ctlecho");
	argv[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve("/bin/stty", argv, envp);
	waitpid(-1, NULL, 0);
	free(argv[0]);
	free(argv[1]);
}

void	mini_init(t_minish *minish, char **argv, char **env)
{
	int		i;
	int		k;

	ft_ctrlc(env);
	sub_init(minish);
	minish->env_list = NULL;
	minish->argv_list = NULL;
	minish->paths_list = NULL;
	minish->ft_argv = NULL;
	i = 1;
	k = 0;
	while (env[k])
		add_t(&minish->env_list, new_(env[k++], i++));
	minish->ft_env = NULL;
	minish->temp = NULL;
	minish->temporary = NULL;
	minish->set = set_builder();
	minish->name = ">>> ";
	minish->n_pipes = 0;
	minish->stdin_cpy = dup(0);
	minish->stdout_cpy = dup(1);
	minish->path_flag = 0;
	minish->system_path = getenv("PWD");
	set_paths(minish);
	shlvl(minish);
}
