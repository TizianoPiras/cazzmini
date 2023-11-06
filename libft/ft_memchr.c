/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:42:28 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/11 16:59:42 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	p;
	unsigned char	*str;

	str = ((unsigned char *)s);
	i = 0;
	p = (unsigned char)c;
	if (!s && !c && !n)
		return (NULL);
	while (i < n)
	{
		if (str[i] != p)
			i++;
		else
			return ((unsigned char *)&str[i]);
	}
	return (NULL);
}
