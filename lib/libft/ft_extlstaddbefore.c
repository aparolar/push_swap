/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extlstaddbefore.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:03:53 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/18 00:27:08 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_extlst	*ft_extlstaddbefore(t_extlst *lst, void *content)
{
	t_extlst	*node;

	node = 0;
	if (lst)
	{
		node = ft_extlstclone(lst);
		if (node)
		{
			node->content = content;
			node->after = lst;
			lst->before = node;
			if (lst == lst->begin)
			{
				lst->begin = node;
				node->begin = node;
			}
			*node->count += 1;
		}
	}
	return (node);
}
