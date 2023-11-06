/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:41:21 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/11 16:59:42 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long int n)
{
	long int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			j;
	int			a;
	long int	pd;

	a = -1;
	pd = (long int)n;
	j = ft_count(pd);
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	((char *)res)[j--] = '\0';
	if (n < 0)
	{
		pd *= -1;
		((char *)res)[0] = '-';
		a = 0;
	}
	while (j > a)
	{
		((char *)res)[j--] = (pd % 10) + 48;
		pd /= 10;
	}
	return (res);
}
