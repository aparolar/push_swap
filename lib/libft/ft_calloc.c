/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:20:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/18 11:43:10 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	size *= count;
	ptr = malloc(size);
	if (!ptr)
		return (0);
	while (size > 0)
		((char *)ptr)[--size] = 0;
	return (ptr);
}
