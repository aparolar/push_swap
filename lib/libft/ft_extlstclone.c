/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extlstclone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:31:43 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/17 20:12:29 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_extlst	*ft_extlstclone(t_extlst *lst)
{
	t_extlst	*clone;

	clone = 0;
	if (lst)
	{
		clone = ft_calloc(1, sizeof(t_extlst));
		if (clone)
		{
			clone->begin = lst->begin;
			clone->end = lst->end;
			clone->before = lst->before;
			clone->after = lst->after;
			clone->content = lst->content;
			clone->count = lst->count;
		}
	}
	return (clone);
}
