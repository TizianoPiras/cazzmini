/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:48:54 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/26 11:27:19 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static void	path_related(t_shell *mini, char *temp, int i)
{
	char	*res;

	res = check_path(mini, temp);
	if (temp[0] == '/' && check_path2(mini, temp) == 1
		&& check_builtin_presence(mini, temp) == 1)
		its_a_command(mini, temp);
	else if (res != NULL && check_builtin_presence(mini, temp) == 1)
		its_a_command(mini, temp);
	else if (res == NULL)
	{
		its_not_a_command(mini, temp, i);
		if (mini->exit == 1)
			return ;
	}
	if (ft_strcmp((*mini->high)->str, "||") == 0
		|| ft_strcmp((*mini->high)->str, "&&") == 0)
	{
		mini->flags.command_separator = 1;
		mini->command_presence = 0;
	}
	if (temp[0] == '$' && (*mini->high)->order == 0 && i == 0)
		mini->dollar_flag = 1;
	free(res);
}

static int	not_path_related(t_shell *mini, char **temp, int i)
{
	if (temp[i][0] == '(')
		i = reassembling_brackets(mini, temp, i);
	else if (temp[i][0] == '-')
	{
		if ((*mini->high)->argument == NULL)
			its_a_flag(mini, temp[i]);
		else
			((*mini->high)->argument = ft_strjoin_mini((*mini->high)->argument,
						temp[i], FREE, NO_FREE));
	}
	else if (temp[i][0] == '\'' || temp[i][0] == '\"')
		i = reassembling_strings(mini, temp, i);
	return (i);
}

static void	plug(t_shell *mini, char **temp, int i)
{
	if ((!apices(temp[i], '\'', 1)
			|| !apices(temp[i], '\"', 1))
		&& (*mini->high)->argument == NULL)
		(*mini->high)->argument = ft_strdup(temp[i]);
	else if ((!apices(temp[i], '\'', 1)
			|| !apices(temp[i], '\"', 1))
		&& (*mini->high)->argument != NULL)
		(*mini->high)->argument = ft_strjoin_mini((*mini->high)->argument,
				temp[i], FREE, NO_FREE);
	else if (temp[i][0] == '(' || temp[i][0] == '-'
		|| temp[i][0] == '\'' || temp[i][0] == '\"')
		i = not_path_related(mini, temp, i);
	else if (check_builtin_presence(mini, temp[i]) == 0
		&& (*mini->high)->command == NULL)
		(*mini->high)->command = ft_strdup(temp[i]);
	else
		path_related(mini, temp[i], i);
}

static void	anal(t_shell *mini, char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		plug(mini, temp, i);
		i++;
		if (temp[i] == NULL && (*mini->high)->command != NULL)
			checking_node_vilidity(mini);
		if (mini->exit == 1)
			return ;
	}
}

void	analizer(t_shell *mini, char **envp)
{
	char	**temp;

	temp = ft_echo_split(mini, (*mini->high)->str, 32);
	anal(mini, temp);
	if ((*mini->high)->command == NULL && (*mini->high)->redirect == NULL)
	{
		if (ft_strncmp((*mini->high)->str, "$?", 2) == 0)
		{
			if ((*mini->high)->str && (*mini->high)->str[2] != ' ')
			{
				(*mini->high)->str = ft_strtrim((*mini->high)->str, "$?");
				printf("%d%s: command not found\n", g_exit_status, (*mini->high)->str);
			}
			else
				printf("%d: command not found\n", g_exit_status);
		}
		else
			printf("command not found\n");
		mini->flag_status = 127;
	}
	if (ft_strcmp((*mini->high)->str, "expr"))
		echo_replacer(mini, (*mini->high));
	free_matrix(temp);
}
