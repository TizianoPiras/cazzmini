/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:44:43 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/11 16:59:42 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str);

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (NULL);
	k = 0;
	j = ft_strlen(s1);
	i = 0;
	while (s1[k] && ft_check(s1[k], set))
		k++;
	while (j > k && ft_check(s1[j - 1], set))
		j--;
	res = malloc(sizeof(char) * (j - k + 1));
	if (!res)
		return (NULL);
	while (k < j)
	{
		res[i] = s1[k];
		i++;
		k++;
	}
	res[i] = 0;
	return (res);
}
