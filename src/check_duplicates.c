/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:01:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/12/27 22:24:55 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_duplicates(t_pa_list *tpalist)
{
	t_pa_list	*tmp1;
	t_pa_list	*tmp2;

	tmp1 = tpalist->next;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void	assign_indexs(t_pa_list *lst)
{
	t_pa_list	*node;
	int			index;
	int			value;

	index = 0;
	value = INT_MIN;
	while (index++ < *lst->size)
	{
		node = lst->next;
		while (node)
		{
			if (find_min_value(node, value) == node->value)
			{
				node->index = index;
				value = node->value;
				break ;
			}
			node = node->next;
		}
	}
}
