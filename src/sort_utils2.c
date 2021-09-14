/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:08:53 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/13 19:28:05 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    rotate_value(t_pa_collection *tpc, int value)
{
	size_t	i;

	i = find_node_value(tpc->a, value);
	if (i < ext_lst_get_size(tpc->a) - i)
	{
		while (i-- > 0)
			rotate_a(tpc);
	}
	else
	{
		i = ext_lst_get_size(tpc->a) - i - 1;
		while (i-- > 0)
			reverse_rotate_a(tpc);
	}
}

void    rotate_value_b(t_pa_collection *tpc, int value)
{
	size_t	i;

	i = find_node_value(tpc->b, value);
	if (i < ext_lst_get_size(tpc->b) - i)
	{
		while (i-- > 0)
			rotate_b(tpc);
	}
	else
	{
		i = ext_lst_get_size(tpc->b) - i - 1;
		while (i-- > 0)
			reverse_rotate_b(tpc);
	}
}

int		have_positives(t_pa_list *tpalist)
{
	t_pa_list	*node;

	node = ext_lst_get_start(tpalist)->next;
	while (node)
	{
		if (node->value > 0)
			return (1);
		node = node->next;
	}
	return (0);
}

int		have_negatives(t_pa_list *tpalist)
{
	t_pa_list	*node;

	node = ext_lst_get_start(tpalist)->next;
	while (node)
	{
		if (node->value < 0)
			return (1);
		node = node->next;
	}
	return (0);
}

int		find_max_value(t_pa_list *node)
{
	int			max;
	t_pa_list	*tnode;

	max = INT_MIN;
	tnode = ext_lst_get_start(node)->next;
	while (tnode)
	{
		if (tnode->value > max)
			max = tnode->value;
		tnode = tnode->next;
	}
	return (max);
}

