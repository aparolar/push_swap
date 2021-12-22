/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:32:04 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/20 11:37:24 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*node;

	size = 0;
	if (lst)
	{
		size = 1;
		node = lst;
		while (node->next)
		{
			node = node->next;
			size++;
		}
	}
	return (size);
}
