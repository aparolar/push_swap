/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extlstaddafter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:03:53 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/18 00:27:56 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_extlst	*ft_extlstaddafter(t_extlst *lst, void *content)
{
	t_extlst	*node;

	node = 0;
	if (lst)
	{
		node = ft_extlstclone(lst);
		if (node)
		{
			node->content = content;
			node->before = lst;
			lst->after = node;
			if (lst == lst->end)
			{
				lst->end = node;
				node->end = node;
			}
			*node->count += 1;
		}
	}
	return (node);
}
