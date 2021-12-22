/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extlstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:42:13 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/18 11:16:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_extlstunlink(t_extlst *lst)
{
	if (*lst->count > 1)
	{
		if (lst == lst->begin)
			lst->after->begin = lst->after;
		if (lst == lst->end)
			lst->before->end = lst->before;
		lst->before->after = lst->after;
		lst->before->begin = lst->after->begin;
		lst->after->before = lst->before;
		lst->after->end = lst->before->end;
	}
}

void	ft_extlstdelone(t_extlst *lst, void (*del)(void*))
{
	t_extlst	*delone;

	if (lst && del)
	{
		delone = lst;
		del(delone->content);
		if (*lst->count > 1)
			ft_extlstunlink(lst);
		*delone->count -= 1;
		free(delone);
		delone = NULL;
	}
}
