/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:40:01 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/11 16:59:42 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sign(char c)
{
	int	sign;

	sign = 1;
	if (c == '-')
		sign *= -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] != '\0' && (str[i] >= 9 && str[i] <= 13))
		|| str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign *= ft_sign(str[i]);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		j = (j * 10) + (str[i] - 48);
		i++;
	}
	return ((int)(sign * j));
}
