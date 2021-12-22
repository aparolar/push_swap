/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extlstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:18:48 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/18 11:22:36 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_extlstclear(t_extlst *lst, void (*del)(void *))
{
	t_extlst	*ndel;

	if (lst && del)
	{
		ndel = lst;
		while (lst)
		{
			ndel = lst->after;
			ft_extlstdelone(lst, del);
			lst = ndel;
		}
	}
}
