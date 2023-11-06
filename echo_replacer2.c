/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_replacer2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:45:47 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/26 11:25:42 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*echo_expanding_d(t_shell *mini, char *s)
{
	char	*en;

	en = get_my_env(mini, s);
	if (s[0] == '?')
	{
		if (mini->flag_status != 0)
		{
			en = ft_itoa(g_exit_status);
			mini->flag_status = 0;
			g_exit_status = 0;
		}
		else
			en = ft_itoa(WEXITSTATUS(g_exit_status));
	}
	if (en == NULL)
	{
		free(en);
		return(s);
	}
	free(s);
	return (en);
}

char	**tyu(t_args *node)
{
	char	*str;
	char	**matrix;

	str = ft_quite_strong(node);
	matrix = ft_split(str, 6);
	free(str);
	return (matrix);
}
