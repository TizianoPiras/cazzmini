/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:44:01 by tpiras            #+#    #+#             */
/*   Updated: 2023/09/11 16:59:42 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	len;

	if (!dst && n == 0)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size > n || n == 0)
		return (n + src_size);
	len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && (len + 1) < n)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (dst_size + ft_strlen(src));
}
