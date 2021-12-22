/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:54:45 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/18 17:10:29 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*p_src;
	char	*p_dst;

	p_src = (char *)src;
	p_dst = (char *)dst;
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == (char)c)
			return (p_dst + i + 1);
		i++;
	}
	return (NULL);
}
