/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:48:14 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/13 14:31:03 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	lh;
	size_t	ln;

	i = 0;
	lh = ft_strlen(haystack);
	ln = ft_strlen(needle);
	if (haystack == needle || !ln)
		return ((char *)haystack);
	if ((ln > lh && lh < len) || lh < ln)
		return (NULL);
	while ((i < len && (len - i) >= ln))
	{
		if (!ft_strncmp(((char *)haystack) + i, needle, ln))
			return (((char *)haystack) + i);
		i++;
	}
	return (NULL);
}
