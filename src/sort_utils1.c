/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:13:09 by aparolar          #+#    #+#             */
/*   Updated: 2021/10/20 10:31:11 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_node_value(t_pa_list *node, int value)
{
	int			i;
	t_pa_list	*tnode;

	i = 0;
	tnode = (*node->start)->next;
	while (tnode)
	{
		if (tnode->value == value)
			break ;
		tnode = tnode->next;
		i++;
	}
	return (i);
}

int	find_min_value(t_pa_list *node, int min_value)
{
	int			min;
	t_pa_list	*tnode;

	min = INT_MAX;
	tnode = (*node->start)->next;
	while (tnode)
	{
		if (tnode->value < min && tnode->value > min_value)
			min = tnode->value;
		tnode = tnode->next;
	}
	return (min);
}

int	is_sorted(t_pa_list *tpalist)
{
	tpalist = *tpalist->start;
	while (tpalist)
	{
		if (tpalist->next)
		{
			if (tpalist->index > tpalist->next->index)
				return (0);
		}
		tpalist = tpalist->next;
	}
	return (1);
}

void	rotate_value(t_pa_collection *tpc, int value)
{
	size_t	i;

	i = find_node_value(tpc->a, value);
	if (i < *tpc->a->size - i)
	{
		while (i-- > 0)
			rotate_a(tpc);
	}
	else
	{
		i = *tpc->a->size - i - 1;
		while (i-- > 0)
			reverse_rotate_a(tpc);
	}
}

int	find_max_value(t_pa_list *node)
{
	int			max;
	t_pa_list	*tnode;

	max = INT_MIN;
	tnode = (*node->start)->next;
	while (tnode)
	{
		if (tnode->value > max)
			max = tnode->value;
		tnode = tnode->next;
	}
	return (max);
}
