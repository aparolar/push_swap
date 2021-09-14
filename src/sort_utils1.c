/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:13:09 by aparolar          #+#    #+#             */
/*   Updated: 2021/09/14 10:54:41 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		find_node_value(t_pa_list *node, int value)
{
	int			i;
	t_pa_list	*tnode;

	i = 0;
	tnode = ext_lst_get_start(node)->next;
	while (tnode)
	{
		if (tnode->value == value)
			break ;
		tnode = tnode->next;
		i++;
	}
	return (i);
}

int		find_min_value(t_pa_list *node, int min_value)
{
	int			min;
	t_pa_list	*tnode;

	min = INT_MAX;
	tnode = ext_lst_get_start(node)->next;
	while (tnode)
	{
		if (tnode->value < min && tnode->value > min_value)
			min = tnode->value;
		tnode = tnode->next;
	}
	return (min);
}

int  is_sorted(t_pa_list *tpalist)
{
	tpalist = ext_lst_get_start(tpalist)->next;
	while (tpalist)
	{
		if (tpalist->next)
		{
			if (tpalist->value > tpalist->next->value)
				return (0);
		}
		tpalist = tpalist->next;
	}
	return (1);
}

int  is_reverse_sorted(t_pa_list *tpalist)
{
	tpalist = ext_lst_get_start(tpalist)->next;
	while (tpalist)
	{
		if (tpalist->next)
		{
			if (tpalist->value < tpalist->next->value)
				return (0);
		}
		tpalist = tpalist->next;
	}
	return (1);
}

void	quikly_sort(t_pa_collection *tpc)
{
	t_pa_list		*a;
	int				rel;

	a = tpc->a->next;
	while (a)
	{
		rel += a->value;
		a = a->next;
	}
	rel /= ext_lst_get_size(tpc->a) - 1;
	a = tpc->a->next;
	//print_lists(tpc);
	while (a && ext_lst_get_size(a) > 2 && find_min_value(tpc->a, INT_MIN) <= rel)
	{
		a = tpc->a->next;
		if (a->value <= rel)
			push_b(tpc);
		else
			rotate_a(tpc);
		a = tpc->a->next;
	}
//	while (ext_lst_get_size(tpc->b) > 1)
//		push_a(tpc);
	//print_lists(tpc);
}