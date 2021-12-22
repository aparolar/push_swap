/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:18:18 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/20 18:56:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	ret = NULL;
	if (lst && f)
	{
		while (lst != NULL)
		{
			tmp = ft_lstnew(f(lst->content));
			if (tmp == NULL)
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
			ft_lstadd_back(&ret, tmp);
			lst = lst->next;
		}
	}
	return (ret);
}
