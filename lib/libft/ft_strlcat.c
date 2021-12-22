/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:53:15 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/15 10:44:18 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	char	*p_s;

	p_s = (char *)src;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize < dlen || (!dstsize && src))
		return (slen + dstsize);
	while (*p_s && dlen < (dstsize - 1))
	{
		dst[dlen] = *p_s;
		dlen++;
		p_s++;
	}
	dst[dlen] = 0;
	while (*p_s++)
		dlen++;
	return (dlen);
}
