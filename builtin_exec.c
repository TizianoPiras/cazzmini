/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:45:24 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/22 18:08:39 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	command_env(t_shell *mini)
{
	int		j;
	char	*dollar;
	char	*argument;

	j = 0;
	dollar = "$";
	if (mini->new_envp == NULL)
	{
		while (mini->envp[j] != NULL)
		{
			argument = ft_strjoin(dollar, mini->envp[j], NO_FREE, NO_FREE);
			if (!(*mini->list)->argument)
				printf("%s\n", mini->envp[j]);
			else if (ft_strncmp(argument, (*mini->list)->argument,
					ft_strlen((*mini->list)->argument)) == 0)
				printf("%s\n", mini->envp[j]);
			j++;
		}
	}
	else
		command_env2(mini, dollar);
}

void	command_pwd(t_shell *mini, t_args *current)
{
	char	pwd_path[1024];

	if (getcwd(pwd_path, sizeof(pwd_path)) != NULL)
		printf("%s\n", pwd_path);
	else
	{
		printf("pwd: error\n");
		mini->flag_status = 1;
		g_exit_status = 1;
	}
}

static void	create_path(t_shell *mini, char *path)
{
	mini->main_path = ft_strtrim(mini->main_path, "$ ");
	mini->main_path = ft_strjoin(mini->main_path, "/", FREE,
			NO_FREE);
	mini->main_path = ft_strjoin(mini->main_path, path, FREE,
			NO_FREE);
	mini->main_path = ft_strtrim(mini->main_path, "/");
	mini->main_path = ft_strjoin(mini->main_path, "$ ", FREE,
			NO_FREE);
}

static void	command_cd2(t_shell *mini, char *path)
{
	if (ft_strcmp(path, "..") == 0)
	{
		mini->main_path = ft_substr(mini->main_path, 0,
				ft_strlen(mini->main_path)
				- ft_strchr(rev_string(mini->main_path), '/') - 1);
		mini->main_path = ft_strjoin(mini->main_path, "$ ", FREE,
				NO_FREE);
	}
	else if (ft_strcmp(path, ".") == 0)
		return ;
	else
		create_path(mini, path);
}

void	command_cd(t_shell *mini, t_args *node, char *arg)
{
	char	*curr_path;
	char	*path;

	curr_path = get_my_env(mini, "PWD");
	if (!arg)
		path = get_my_env(mini, "HOME");
	else
		path = arg;
	if (chdir(path) == -1)
	{
		printf("chdir error: Bad address %s\n", path);
		mini->flag_status = 1;
		g_exit_status = 1;
	}
	else
		command_cd2(mini, path);
}
