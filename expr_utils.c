/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:59:39 by ertiz             #+#    #+#             */
/*   Updated: 2023/09/21 11:59:54 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	command_expr(t_shell *mini, char **envp, t_args *current)
{
	char	*res;

	if ((current->argument == NULL && current->flags != NULL)
		|| (current->argument != NULL
			&& (ft_strncmp(current->argument, "\"-n\"", 4) == 0)))
		return ;
	else if (current->argument == NULL && current->flags == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	if (current->argument[0] == '\'' && current->argument != NULL)
	{
		current->argument = ft_strtrim(current->argument, "\'");
		write(1, current->argument, ft_strlen(current->argument));
		if (current->flags == NULL)
			write(1, "\n", 1);
		return ;
	}
	echo_replacer(mini, current);
	res = ft_strtrim(current->argument, "\"");
	free(current->argument);
	current->argument = ft_strdup(res);
	free(res);
	echo_print(current);
}
