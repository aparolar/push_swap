/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:31:34 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/20 13:52:33 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ndel;

	if (lst && del)
	{
		ndel = *lst;
		while (*lst)
		{
			ndel = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = ndel;
		}
	}
}
