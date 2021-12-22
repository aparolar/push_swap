/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extlstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:39:27 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/17 17:07:48 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_extlst	*ft_extlstnew(void *content)
{
	t_extlst	*node;
	size_t		count;

	node = ft_calloc(1, sizeof(t_extlst));
	if (node)
	{
		count = 1;
		node->count = &count;
		node->begin = node;
		node->end = node;
		node->before = node;
		node->after = node;
		node->content = content;
	}
	return (node);
}
