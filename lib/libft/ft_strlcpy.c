/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:50:40 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/14 20:36:21 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;

	if (!dst && !src)
		return (0);
	lsrc = ft_strlen(src);
	if (!dstsize)
		return (lsrc);
	if (dstsize > lsrc)
	{
		ft_memcpy(dst, src, lsrc);
		dst[lsrc] = 0;
		dstsize = lsrc;
	}
	else if (dstsize <= lsrc)
	{
		ft_memcpy(dst, src, dstsize);
		dst[dstsize - 1] = 0;
		dstsize = lsrc;
	}
	return (dstsize);
}
