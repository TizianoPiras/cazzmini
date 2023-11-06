/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:43:44 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/11 16:59:42 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		k;

	k = ft_strlen(s1) + 1;
	i = 0;
	s2 = (char *)malloc(k);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		((char *)s2)[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
